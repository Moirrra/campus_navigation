#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QPushButton>
#include <QPainter>
#include <QListWidgetItem>
#include <QCompleter>
#include <QStringListModel>
#include <QComboBox>
#include <QtGlobal>

#include "sqlhelp.h"
#include "graph.h"

#define shahecnt 68
#define benbucnt 93
#define inf 32767

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mySqlHelp = new SqlHelp();

    InitData();

    ui->widget_map->installEventFilter(this);
    graph = new Graph(shahecnt, benbucnt);

    //逻辑地址模糊搜索
    logicCompleter = new QCompleter();
    logicCompleter->setFilterMode(Qt::MatchContains);               //包含
    logicCompleter->setCompletionMode(QCompleter::PopupCompletion); //弹出
    logicCompleter->setCaseSensitivity(Qt::CaseInsensitive);        //不区分大小写
    logicAddrs = mySqlHelp->GetTableColumnValue("logicMap", "logicAddr");
    QStringListModel *listModel;
    listModel = new QStringListModel(logicAddrs);
    logicCompleter->setModel(listModel);
    //导航
    ui->lineEdit_src->setCompleter(logicCompleter);
    ui->lineEdit_dest->setCompleter(logicCompleter);
    //查询
    ui->lineEdit_logicSearch->setCompleter(logicCompleter);

    //状态初始化
    currentType = 1;
    searchFind = 0;
    alreadyStart = 0;
    alreadyEnd = 0;
    finishLine = 0;
    transfer = 0;
    startTransfer = 0;
    alreadyTransfer = 0;
    wait = 0;
    paintTimer = new QTimer();
    minuteTimer = new QTimer();
    waitTimer = new QTimer();
    transferTimer = new QTimer();
    connect(paintTimer, SIGNAL(timeout()), this, SLOT(changeStatus()));
    connect(minuteTimer, &QTimer::timeout, [=](){
        if(!startTransfer) mTime = mTime.addSecs(60);
        else mTime = mTime.addSecs(600);
        ui->label_mtime->setText(mTime.toString("yyyy/MM/dd hh:mm"));
    });
    connect(waitTimer, &QTimer::timeout, [=](){
        wait--;
        update();
        if (wait == 0)
        {
            waitTimer->stop();
            startTransfer = 1;
            paintFlag = 1;
            transferTimer->start(1000);
            setLog(QString("/* %1  跨校区中......预计用时 %2 min\n").arg(mTime.toString("yyyy/MM/dd hh:mm")).arg(transfer));
        }
    });
    connect(transferTimer, &QTimer::timeout, [=](){
        transfer-=10;
        update();
        if (transfer == 0)
        {
            transferTimer->stop();
            setLog(QString("/* %1  已到达另一校区").arg(mTime.toString("yyyy/MM/dd hh:mm")));
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * @usage 绑定数据至控件
 * @brief void MainWindow::InitData
 * @author ts
 */
void MainWindow::InitData()
{
    /*生成用户ID*/
    createID();
    ui->label_ID->setText(QString::number(userID));

    /* 下拉框数据绑定 */
    //src
    if (ui->comboBox_src1->currentText() == "沙河")
        mySqlHelp->BindDataToCombox("shahe", "name", "where type<>'fork'", ui->comboBox_src2);
    connect(ui->comboBox_src1, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
            [=](const QString &text)
    {
        ui->comboBox_src2->clear();
        if (text == "沙河")
            mySqlHelp->BindDataToCombox("shahe", "name", "where type<>'fork'", ui->comboBox_src2);
        else if (text == "本部")
            mySqlHelp->BindDataToCombox("benbu", "name", "where type<>'fork'", ui->comboBox_src2);
    });
    //dest
    if (ui->comboBox_dest1->currentText() == "沙河")
        mySqlHelp->BindDataToCombox("shahe", "name", "where type<>'fork'", ui->comboBox_dest2);
    connect(ui->comboBox_dest1, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
            [=](const QString &text)
    {
        ui->comboBox_dest2->clear();
        if (text == "沙河")
            mySqlHelp->BindDataToCombox("shahe", "name", "where type<>'fork'", ui->comboBox_dest2);
        else if (text == "本部")
            mySqlHelp->BindDataToCombox("benbu", "name", "where type<>'fork'", ui->comboBox_dest2);
    });
    //pass
    if (ui->comboBox_pass1->currentText() == "沙河")
        mySqlHelp->BindDataToCombox("shahe", "name", "where type<>'fork'", ui->comboBox_pass2);
    connect(ui->comboBox_pass1, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
            [=](const QString &text)
    {
        ui->comboBox_pass2->clear();
        if (text == "沙河")
            mySqlHelp->BindDataToCombox("shahe", "name", "where type<>'fork'", ui->comboBox_pass2);
        else if (text == "本部")
            mySqlHelp->BindDataToCombox("benbu", "name", "where type<>'fork'", ui->comboBox_pass2);
    });
    //pos
    if (ui->comboBox_pos1->currentText() == "沙河")
        mySqlHelp->BindDataToCombox("shahe", "name", "where type<>'fork'", ui->comboBox_pos2);
    connect(ui->comboBox_pos1, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
            [=](const QString &text)
    {
        ui->comboBox_pos2->clear();
        if (text == "沙河")
            mySqlHelp->BindDataToCombox("shahe", "name", "where type<>'fork'", ui->comboBox_pos2);
        else if (text == "本部")
            mySqlHelp->BindDataToCombox("benbu", "name", "where type<>'fork'", ui->comboBox_pos2);
    });

    /*初始化出发时间为当前时间*/
    QDateTime *curtime = new QDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_setOut->setDateTime(*curtime);

    /*spinbox和slider绑定*/
    ui->spinBox->setRange(10, 150);
    ui->horizontalSlider->setRange(10, 150);
    ui->spinBox->setValue(80);
    ui->horizontalSlider->setValue(80);

    connect(ui->spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), ui->horizontalSlider, &QSlider::setValue);
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

/*
 * @usage 重写时间过滤器
 * @brief bool MainWindow::eventFilter
 * @param watched 对象
 * @param event 时间
 * @author ts
 */
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->widget_map && event->type() == QEvent::Paint)
    {
        showPaint(); //响应函数
    }
    return QWidget::eventFilter(watched, event);
}

/*
 * @usage 画图
 * @brief void MainWindow::showPaint
 * @author ts
 */
void MainWindow::showPaint()
{
    QPainter painter(ui->widget_map);
    QPen pen;
    painter.setPen(pen);
    QPoint offset(60, 100);
    QPoint offset2(200, 30);
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    //背景地图
    QSize mapSize = ui->widget_map->size() * 0.9;
    QPixmap map1 = QPixmap(":/img/shahe.png").scaled(mapSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap map2 = QPixmap(":/img/benbu.png").scaled(mapSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap bus = QPixmap(":/img/bus.png").scaled(QSize(300, 200), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap busWait = QPixmap(":/img/bus.png").scaled(QSize(80, 50), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    //设置起始地图
    if (ui->label_curPos->text().contains("本部") && !alreadyStart && !searchFind)
    {
        currentType = 2;
    }
    if (ui->label_curPos->text().contains("沙河") && !alreadyStart && !searchFind)
    {
        currentType = 1;
    }
    //跨校区
    if (startTransfer)
    {
        painter.drawPixmap(300, 300, bus);
        QString str = QString("剩余时间: %1 min").arg(transfer);
        painter.drawText(300, 510, str);
    }
    //正常显示地图
    else
    {
        if (currentType == 1)
        {
            painter.drawPixmap(30, 100, map1);
            //线
            pen.setColor(Qt::gray);
            pen.setWidth(2);
            painter.setPen(pen);
            for (int i = 0; i < shahecnt; i++)
            {
                for (int j = 0; j < shahecnt; j++)
                    if (graph->adjMatrix1[i][j].length < inf)
                        painter.drawLine(graph->qpoint1[i] + offset, graph->qpoint1[j] + offset);
            }
            //点
            pen.setColor(Qt::black);
            pen.setWidth(4);
            painter.setPen(pen);
            for (int i = 0; i < shahecnt; i++)
                painter.drawPoint(graph->qpoint1[i] + offset);
            if (wait) //等车
            {
                if (transfer == 60)
                    painter.drawText(60, 380, "等待班车中");
                if (transfer == 90)
                    painter.drawText(60, 380, "等待公交车中");
                QString str = QString("仍需等待 %1 min").arg(wait);
                painter.drawText(60, 420, str);
                painter.drawPixmap(55, 310, busWait);
            }
        }
        else if (currentType == 2)
        {
            painter.drawPixmap(150, 0, map2);
            //线
            pen.setColor(Qt::gray);
            pen.setWidth(2);
            painter.setPen(pen);
            for (int i = 0; i < benbucnt; i++)
            {
                for (int j = 0; j < benbucnt; j++)
                {
                    if (graph->adjMatrix2[i][j].length < inf)
                        painter.drawLine(graph->qpoint2[i] + offset2, graph->qpoint2[j] + offset2);
                }
            }
            //点
            pen.setColor(Qt::black);
            pen.setWidth(4);
            painter.setPen(pen);
            for (int i = 0; i < benbucnt; i++)
                painter.drawPoint(graph->qpoint2[i] + offset2);
            if (wait) //等车
            {
                if (transfer == 60)
                    painter.drawText(60, 530, "等待班车中");
                if (transfer == 90)
                    painter.drawText(60, 530, "等待公交车中");
                QString str = QString("仍需等待 %1 min").arg(wait);
                painter.drawText(60, 550, str);
                painter.drawPixmap(80, 460, busWait);
            }
        }
    }

    if (searchFind) //显示查询结果的点
    {
        qDebug() << "search draw";
        pen.setColor(Qt::yellow);
        pen.setWidth(5);
        painter.setPen(pen);
        for (int i = 0; i < list.size(); i++)
        {
            int id = graph->locateVex(searchType, list[i]);
            QPointF point = graph->getPoint(searchType, id);
            if (searchType == 1)
                painter.drawPoint(point + offset);
            else
                painter.drawPoint(point + offset2);
        }
        pen.setColor(Qt::green);
        painter.setPen(pen);
        QPointF point = graph->getPoint(searchType, searchPointId);
        if (searchType == 1)
            painter.drawPoint(point + offset);
        else
            painter.drawPoint(point + offset2);
    }

    if (alreadyStart && !startTransfer && !wait &&!searchFind) //开始模拟
    {
        //画点
        pen.setColor(Qt::red);
        pen.setWidth(4);
        painter.setPen(pen);
        //标注途经点
        if (currentType == 1)
            for (int i = 0; i < paintPointList.size(); i++)
                painter.drawPoint(paintPointList[i] + offset);
        else if (currentType == 2)
            for (int i = 0; i < paintPointList2.size(); i++)
                painter.drawPoint(paintPointList2[i] + offset2);
        //画线
        pen.setWidth(2);
        painter.setPen(pen);
        //已画的线
        if (alreadyEnd && alreadyTransfer) //完整的路线
        {
            if (currentType == 1)
                for (int i = 0; i < paintPointList.size() - 1; i++)
                    painter.drawLine(paintPointList[i] + offset, paintPointList[i + 1] + offset);
            else
                for (int i = 0; i < paintPointList2.size() - 1; i++)
                    painter.drawLine(paintPointList2[i] + offset2, paintPointList2[i + 1] + offset2);
        }
        else if (passNum >= 1) //模拟过程已走路线
        {
            qDebug() << "passNum = " << passNum << "\n";
            for (int i = 0; i < passNum; i++)
            {
                if (currentType == 1)
                {
                    painter.drawLine(paintPointList[i] + offset, paintPointList[i + 1] + offset);
                }
                else if (currentType == 2)
                {
                    painter.drawLine(paintPointList2[i] + offset2, paintPointList2[i + 1] + offset2);
                }
            }
        }
        //正在走的路
        if (!alreadyEnd && (paintFlag > 0))
        {
            if (currentType == 1)
            {
                startPoint = paintPointList[passNum];
                endPoint = paintPointList[passNum+1];
                currentPoint = startPoint+currentProgress*(endPoint-startPoint);
                painter.drawLine(startPoint+offset,currentPoint+offset);
            }
            if (currentType == 2)
            {
                startPoint = paintPointList2[passNum];
                endPoint = paintPointList2[passNum+1];
                currentPoint = startPoint+currentProgress*(endPoint-startPoint);
                painter.drawLine(startPoint+offset2,currentPoint+offset2);
            }
            if (currentPoint == endPoint)
                finishLine = 1;
        }
    }
}

/*
 * @usage 获取模拟路线的点和时间
 * @brief void MainWindow::changeStatus
 * @return 0 不用模拟 1需要模拟 -1直接等车跨校区
 * @author ts
 */
int MainWindow::getPaintList()
{
    paintPointList.clear();
    paintPointList2.clear();
    if (changeType >= 3)
    {
        //校区1
        for (int i = 0; i < strategy->route[0].size(); i++)
            paintPointList.append(graph->getPoint(1, strategy->route[0][i]));
        for (int i = 1; i < strategy->route[2].size(); i++) //如果校区1有途经点
            paintPointList.append(graph->getPoint(1, strategy->route[2][i]));
        //校区2
        for (int i = 0; i < strategy->route[1].size(); i++)
            paintPointList2.append(graph->getPoint(2, strategy->route[1][i]));
        for (int i = 1; i < strategy->route[3].size(); i++)
            paintPointList2.append(graph->getPoint(2, strategy->route[3][i]));

        timeList = strategy->troute[0] + strategy->troute[2];  //校区1
        timeList2 = strategy->troute[1] + strategy->troute[3]; //校区2
        qDebug() << "paintPointList.size = " << paintPointList.size();
        qDebug() << "paintPointList2.size = " << paintPointList2.size();
        qDebug() << "timelist.size = " << timeList.size();
        qDebug() << "timelist2.size = " << timeList2.size();
        if (paintPointList.isEmpty() && paintPointList2.isEmpty()) //SRC1-SRC2 不用模拟
            return 0;
        if ((changeType == 3 && timeList.isEmpty()) || (changeType == 4 && timeList2.isEmpty()))
            return -1;
    }
    else
    {
        if (changeType == 1) //只在校区1
        {
            for (int i = 0; i < strategy->route[0].size(); i++)
                paintPointList.append(graph->getPoint(1, strategy->route[0][i]));
            for (int i = 1; i < strategy->route[2].size(); i++) //如果校区1有途经点
                paintPointList.append(graph->getPoint(1, strategy->route[2][i]));
            timeList = strategy->troute[0] + strategy->troute[2];
        }
        else //changeType==2 只在校区2
        {
            for (int i = 0; i < strategy->route[1].size(); i++)
                paintPointList2.append(graph->getPoint(2, strategy->route[1][i]));
            for (int i = 1; i < strategy->route[3].size(); i++)
                paintPointList2.append(graph->getPoint(2, strategy->route[3][i]));
            timeList2 = strategy->troute[1] + strategy->troute[3];
        }
    }
    return 1;
}

/*
 * @usage 处理模拟路线状态变化
 * @brief void MainWindow::changeStatus
 * @author ts
 */
void MainWindow::changeStatus()
{
    QString mLog = "";//模拟日志
    QString posName;
//    if (mTime >= strategy->endTime)
//        minuteTimer->stop();
    QDateTime curMTime = QDateTime(QDateTime::currentDateTime());
    double dif = beginmTime.msecsTo(curMTime);
    currentMinute = dif / 1000; //已用模拟时间
    //跨校区完成时
    if (startTransfer && !transfer)
    {
        alreadyTransfer = 1;
        startTransfer = 0;
        passNum = 0;
        usedTime = 0;
        usedMinute = currentMinute;
        partTime = 0;
        alreadyEnd = 0;
        if (changeType == 3)
            currentType = 2;
        else
            currentType = 1;
        qDebug()<<"校区 "<<currentType;
        //已达终点
        if ((changeType == 3 && timeList2.isEmpty()) || (changeType == 4 && timeList.isEmpty()))
        {
            update();
            paintTimer->stop();
            alreadyEnd = 1;
        }
    }
    //直接开始等待 + 跨校区
    if(paintFlag==-1 || paintFlag==0)
    {
        paintFlag = -2;
        passNum = 0;
        wait = strategy->waitTime;
        transfer = strategy->transferTool;
        passNum = 0;
        qDebug() << "wait =" << wait;
        if (wait)
        {
            waitTimer->start(1000); //一秒模拟一分钟
            mLog = QString("/* %1  等车中......预计等待时间 %2 min").arg(mTime.toString("yyyy/MM/dd hh:mm")).arg(wait);
            setLog(mLog);
        }
        else//无需等待
        {
            startTransfer = 1;
            transferTimer->start(1000);
            mLog = QString("/* %1  跨校区中......预计用时 %2 min").arg(mTime.toString("yyyy/MM/dd hh:mm")).arg(transfer);
            setLog(mLog);
        }
        usedTime = 0;
        partTime = 1;
    }
    /*每一段路径信息更新*/
    //第二次模拟
    if (changeType == 3 && alreadyTransfer && !timeList2.isEmpty())
    {
        partTime = timeList2[passNum];
    }
    else if (changeType == 4 && alreadyTransfer && !timeList.isEmpty())
    {
        partTime = timeList[passNum];
    }
    //第一次模拟
    else
    {
        if (changeType == 1 || (changeType == 3 && !alreadyTransfer && !timeList.isEmpty()))
        {
            partTime = timeList[passNum];
        }
        else if (changeType == 2 || (changeType == 4&&!alreadyTransfer&& !timeList2.isEmpty()))
        {
            partTime = timeList2[passNum];
        }
    }

    currentProgress = usedTime / partTime;
    if (currentProgress > 1) currentProgress = 1;
    currentPoint = startPoint + currentProgress * (endPoint - startPoint);
    usedTime = currentMinute - usedMinute;
    update();
//    qDebug() << "curm = " << currentMinute;
//    qDebug() << "used Time = " << usedTime;
//    qDebug() << "part Time = " << partTime;


    //走完一小段路
    if (finishLine)
    {
        finishLine = 0;
        //更新已用时间
        usedMinute += usedTime;
        currentProgress = 0;
        //获取当前位置名称
        if (changeType == 1 || (changeType == 3 && !alreadyTransfer) || (changeType == 4 && alreadyTransfer))
        {
            currentPoint = paintPointList[passNum + 1];
            posName = "沙河 " + graph->getPointName(1, currentPoint);
        }
        else
        {
            currentPoint = paintPointList2[passNum + 1];
            posName = "本部 " + graph->getPointName(2, currentPoint);
        }
        ui->label_curPos->setText(posName);
        setLog(QString("/* %1  到达: %2").arg(mTime.toString("yyyy/MM/dd hh:mm")).arg(posName));
        //next path
        //第一次模拟
        if (alreadyTransfer != 1)
        {
            if (((changeType % 2 == 1) && passNum < timeList.size()) ||
                    ((changeType % 2 == 0) && passNum < timeList2.size()))
            {
                usedTime = 0;
                partTime = 0;
                passNum++;
            }
        }
        else
        {
            if (((changeType % 2 == 1) && passNum < timeList2.size()) ||
                    ((changeType % 2 == 0) && passNum < timeList.size()))
            {
                usedTime = 0;
                partTime = 0;
                passNum++;
            }
        }

        //同一校区模拟完成 结束模拟
        if ((passNum >= timeList.size() && changeType == 1) ||
                (passNum >= timeList2.size() && changeType == 2))
        {
            update();
            paintTimer->stop();
            alreadyEnd = 1;
        }

        //第一个校区模拟完成 等车+跨校区
        if (alreadyTransfer!=1 &&((passNum >= timeList.size() && changeType == 3) ||
                                  (passNum >= timeList2.size() && changeType == 4)))
        {
            wait = strategy->waitTime;
            transfer = strategy->transferTool;
            passNum = 0;
            qDebug() << "wait=" << wait;
            if (wait)
            {
                waitTimer->start(1000); //一秒模拟一分钟
                setLog(QString("/* %1  等车中......预计等待时间 %2 min").arg(mTime.toString("yyyy/MM/dd hh:mm")).arg(wait));
            }
            else//无需等待
            {
                startTransfer = 1;
                transferTimer->start(1000);
                setLog(mLog);
            }
        }

        //第二个校区模拟完成
        if(alreadyTransfer&&((changeType==3 && passNum >= timeList2.size())
                             ||(changeType==4 && passNum >= timeList.size())))
        {
            paintTimer->stop();
            alreadyEnd = 1;
        }
    }
    update();
    qDebug() << "finishLine = " << finishLine;
    qDebug() << "changeType = " << changeType;
    qDebug() << "transfer = " << transfer;
    qDebug() << "startTransfer = " << startTransfer;
    qDebug() << "alreadyTransfer = " << alreadyTransfer;

    if(alreadyEnd==1)
    {
        minuteTimer->stop();
        setLog("/**********************************************************/\n");
        ui->btn_search->setEnabled(true);
    }
}

/*
 * @usage 开始导航策略
 * @brief void MainWindow::on_btn_navi_clicked
 * @author ts
 */
void MainWindow::on_btn_navi_clicked()
{
    update(); //地图重绘
    int navType;
    int type1,type2;
    int src,dest;
    int passType = 0, passVex = 0;
    QString navLog = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
    searchFind = 0;
    ui->label_strategy->clear();
    ui->label_curPos->clear();
    strategy = new Strategy(ui->spinBox->value());
    strategy->beginTime = ui->dateTimeEdit_setOut->dateTime();
    mTime = ui->dateTimeEdit_setOut->dateTime();
    navType = ui->comboBox_type->currentIndex();
    strategy->navType = navType;
    if (ui->tabWidget_nav->currentIndex() == 0)//物理位置
    {
        type1 = ui->comboBox_src1->currentIndex() + 1;
        type2 = ui->comboBox_dest1->currentIndex() + 1;
        src = graph->locateVex(type1, ui->comboBox_src2->currentText());
        dest = graph->locateVex(type2, ui->comboBox_dest2->currentText());
        navLog += QString("  用户%1 通过物理位置进行导航\n\n").arg(userID);
    }
    else//逻辑位置
    {
        QString str1 = mySqlHelp->FindValue("logicMap", "logicAddr", ui->lineEdit_src->text(), type1);
        src = graph->locateVex(type1,str1);
        QString str2 = mySqlHelp->FindValue("logicMap", "logicAddr", ui->lineEdit_dest->text(), type2);
        dest = graph->locateVex(type2,str2);
        qDebug()<<"-1";
        navLog += QString("  用户%1 通过逻辑位置进行导航\t 出发地:%2\t 目的地：%3\n\n")
                .arg(userID).arg(ui->lineEdit_src->text()).arg(ui->lineEdit_dest->text());
        if(!type1 || !type2) //输入不合法
        {
            qDebug()<<"error nav input!";
            QMessageBox::warning(this, "警告", "逻辑地址输入不合法，请重新输入！");
            navLog += QString("%1 Warning: 逻辑地址输入不合法！\n\n").arg(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
            setLog(navLog);
            return;
        }
    }

    if(navType==2)
    {//途经点有效
        passType =ui->comboBox_pass1->currentIndex() + 1;
        passVex = graph->locateVex(passType, ui->comboBox_pass2->currentText());
    }

    //无法导航的情况
    if (type1==type2 && src==dest)
    {
        QMessageBox::warning(this, "警告", "起点与终点相同，请重新选择！");
        navLog += QString("%1 Warning: 起点与终点相同，请重新选择！\n\n").arg(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
        setLog(navLog);
        return;
    }
    if(navType==2&&type1==type2&&type1!=passType)
    {
        QMessageBox::warning(this, "警告", "途经点与起点或终点不在同一校区内!");
        navLog += QString("%1 Warning: 途经点与起点或终点不在同一校区内!\n\n").arg(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
        setLog(navLog);
        return;
    }
    int startHour = ui->dateTimeEdit_setOut->dateTime().time().hour();
    if ((type1 != type2) && (startHour >= 23 || startHour < 7))
    {
        QMessageBox::warning(this, "警告", "该起始时间无法进行跨校区导航！");
        navLog += QString("%1 Warning: 该起始时间无法进行跨校区导航！\n\n").arg(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
        setLog(navLog);
        return;
    }

    QString pos1, pos2;
    if(type1==1) pos1 = "沙河";
    else pos1 = "本部";
    if(type2==1) pos2 = "沙河";
    else pos2 = "本部";
    ui->label_strategy->setText(ui->comboBox_type->currentText());
    ui->label_curPos->setText(ui->comboBox_src1->currentText() + " " + ui->comboBox_src2->currentText());

    switch (navType)
    {
    case 0:
        strategy->shortestStrategy(type1, src, type2, dest);
        break;
    case 1:
        strategy->fastestStrategy(type1, src, type2, dest);
        break;
    case 2:
        //途经点与起点或终点重合
        if ((type1 == passType && src == passVex) || (type2 == passType && dest == passVex))
            strategy->shortestStrategy(type1, src, type2, dest);
        else
            strategy->shortestPassStrategy(type1, src, type2, dest, passType, passVex);
        break;
    case 3:
        strategy->fastestToolStrategy(type1, src, type2, dest);
        break;
    }
    getNavLog(navLog,type1, src, type2, dest, passType, passVex);
    setLog(navLog);
    setLog("/*************************模拟线路*************************/");
    //模拟
    ui->btn_search->setEnabled(false);
    alreadyStart = 1;
    alreadyEnd = 0;
    finishLine = 0;
    if (type1 == 1 && type2 == 2)
        changeType = 3;
    else if (type1 == 2 && type2 == 1)
        changeType = 4;
    else if (type1 == type2)
        changeType = type1;
    paintFlag = getPaintList();
    currentPoint = graph->getPoint(type1, src);
    currentMinute = 0;
    currentType = type1;
    currentProgress = 0;
    usedMinute = 0;
    usedTime = 0;
    passNum = 0;
    if (changeType >= 3)
        alreadyTransfer = 0;
    else
        alreadyTransfer = -1;
    beginmTime = QDateTime(QDateTime::currentDateTime());
    paintTimer->start(100);
    minuteTimer->start(1000); //一秒模拟一分钟
    ui->label_totallen->setText(QString::number(strategy->totalLength) + " m");
    ui->label_timecost->setText(strategy->standardTime(strategy->timeCost));
    ui->label_endTime->setText(strategy->endTime.toString("yyyy/MM/dd hh:mm"));
}

/*
 * @usage 查询周边服务设施
 * @brief void MainWindow::on_btn_search_clicked
 * @author ts
 */
void MainWindow::on_btn_search_clicked()
{
    ui->textBrowser_search->clear();
    searchFind = 0;
    QString pos;
    sStrategy = new Strategy(ui->spinBox->value());
    QString sLog = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
    //物理位置
    if (ui->tabWidget_search->currentIndex() == 0)
    {
        searchType = ui->comboBox_pos1->currentIndex() + 1;
        pos = ui->comboBox_pos2->currentText();
        sLog += QString("  用户通过物理位置进行查询\n\n");
    }
    //逻辑位置
    else
    {
        pos = mySqlHelp->FindValue("logicMap", "logicAddr", ui->lineEdit_logicSearch->text(), searchType);
        sLog += QString("  用户通过逻辑位置进行导航,键入: %1 \n\n").arg(ui->lineEdit_logicSearch->text());
        if(!searchType) //输入不合法
        {
            searchFind = 0;
            qDebug()<<"error search input!";
            QMessageBox::warning(this, "警告", "逻辑地址输入不合法，请重新输入！");
            sLog += QString("%1 Warning: 逻辑地址输入不合法！\n\n").arg(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
            setLog(sLog);
            return;
        }
    }
    currentType = searchType;
    list = graph->search(searchType, pos);
    sLog += "/*************************查询结果*************************/\n";
    QString pos1;
    if(searchType==1) pos1 = "沙河";
    else pos1 = "本部";
    sLog += QString("/* 查询中心： %1  %2\n").arg(pos1).arg(pos);
    sLog += "/* 查询类型： 服务设施 教学楼 宿舍楼\n";
    sLog += "/* 查询半径： 100 m\n";
    sLog += "/* 查询结果： 地点\t  最短距离\n";
    if (list.size() != 0)
        searchFind = 1;
    else
    {
        ui->textBrowser_search->append("无");
        sLog += "/*             无";
    }
    int src = graph->locateVex(searchType, pos);
    searchPointId = src;
    for (int i = 0; i < list.size(); i++)
    {
        int dest = graph->locateVex(searchType, list[i]);
        qDebug() << "dest = " << list[i];
        sStrategy->shortestStrategy(searchType, src, searchType, dest);
        int len = sStrategy->totalLength;
        QString str = list[i] + QString(": %1 m").arg(len);
        ui->textBrowser_search->append(str);
        sLog += QString("/*            %1\t  %2 m\n").arg(list[i]).arg(len);
    }
    sLog += "/**********************************************************/\n\n";
    setLog(sLog);
    update();
}


/*
 * @usage 显示日志信息，并写入文件
 * @brief void MainWindow::setLog
 * @param log 存储日志信息
 * @author ts
 */
void MainWindow::setLog(QString log)
{
    ui->logBrowser->append(log);
    QFile logfile("log.txt");
    if (!logfile.open(QFile::WriteOnly|QFile::Append|QFile::Text))
    {
        qDebug()<<"write logfile error!";
    }
    QTextStream textOut(&logfile);
    textOut << log << endl;
    logfile.close();
}

/*
 * @usage 生成导航方案日志
 * @brief void MainWindow::getNavLog
 * @param navLog 存储日志的字符串
 * @param type1 出发地校区类型
 * @param src 出发地序号
 * @param type2 目的地校区类型
 * @param dest 目的地序号
 * @param passType 途径地校区类型
 * @param pass 途径地序号
 * @author ts
 */
void MainWindow::getNavLog(QString &navLog, int type1, int src, int type2, int dest, int passType, int pass)
{
    QString pos1, pos2;
    if(type1==1) pos1 = "沙河";
    else pos1 = "本部";
    if(type2==1) pos2 = "沙河";
    else pos2 = "本部";
    navLog += "/*************************导航方案*************************/\n";
    navLog += QString("/* 出发地:  %1  %2\n").arg(pos1).arg(graph->getVexName(type1,src));
    navLog += QString("/* 目的地:  %1  %2\n").arg(pos2).arg(graph->getVexName(type2,dest));
    if(passType==1) navLog += QString("/* 途径地:  %1  %2\n").arg(pos1).arg(graph->getVexName(passType,pass));
    else navLog += QString("/* 途径地:  %1  %2\n").arg(pos2).arg(graph->getVexName(passType,pass));
    navLog += QString("/* 导航方案:  %1\n").arg(ui->comboBox_type->currentText());
    navLog += QString("/* 开始时间:  %1\n").arg(strategy->beginTime.toString("yyyy/MM/dd hh:mm"));
    navLog += QString("/* 预计到达时间:  %1\n").arg(strategy->endTime.toString("yyyy/MM/dd hh:mm"));
    navLog += QString("/* 预计用时:  %1\n").arg(strategy->standardTime(strategy->timeCost));
    navLog += QString("/* 总距离:  %1 m\n").arg(strategy->totalLength);
    navLog += QString("/* 步行时间:  %1 m/min\n").arg(ui->spinBox->value());
    if(type1!=type2)
    {
        QString tool = "";
        navLog += QString("/* 等车用时:  %1 min\n").arg(strategy->waitTime);
        if(strategy->transferTool==60) tool = "班车";
        else tool = "公交车";
        navLog += QString("/* 跨校区方式:  %1\n").arg(tool);
    }
    navLog += "/**********************************************************/\n\n";
}


/*
 * @usage 随机生成用户ID(0-9999)
 * @brief void MainWindow::createID
 * @author ts
 */
void MainWindow::createID()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    userID = rand()%10000;
}
