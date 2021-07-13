#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "sqlhelp.h"
#include "graph.h"
#include "strategy.h"
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void InitData();
    bool eventFilter(QObject *watched, QEvent *event);
    void showPaint();
    int getPaintList();
    void getNavLog(QString &navLog, int type1, int src,
                      int type2, int dest, int passType, int pass);
    void setLog(QString log);
    void createID();

private:
    Ui::MainWindow *ui;
    SqlHelp *mySqlHelp;
    Graph *graph;
    Strategy *strategy;//导航策略
    Strategy *sStrategy;//查询策略
    QList<QString> passList1;
    QList<QString> passList2;
    QStringList logicAddrs;
    QCompleter *logicCompleter;
    int userID;//开始程序时自动分配的用户ID

    //状态
    int searchFind;//已有查询结果
    int alreadyStart;//已开始导航
    int alreadyEnd;//导航完成
    int alreadyTransfer;//已跨校区
    int startTransfer;//为1启动跨校区
    int finishLine;//走完一段路径
    int changeType;//1 2不变 3：校区1-2  4：校区2-1
    int paintFlag;//0不模拟 1正常 -1直接开始等待
    int transfer; //跨校区剩余时间
    int wait; //剩余等车时间

    //模拟导航
    QTimer *paintTimer;
    QTimer *minuteTimer;
    QTimer *waitTimer;
    QTimer *transferTimer;
    QDateTime mTime; //显示的模拟时间
    QDateTime beginmTime;//开始模拟的当前时间
    QPointF currentPoint;//当前位置
    QPointF startPoint;//路径起点
    QPointF endPoint;//路径终点
    double usedTime;//每条路径的已用时间
    double partTime;//每条路径的总时间
    double currentProgress; //每条路径的进度
    int currentType;//当前所在校区类型
    double currentMinute;//模拟已用时间
    double usedMinute;//走过完整路径用时
    int passNum; //已画路径条数 跨校区重新算
    QList<QPointF> paintPointList;//校区1
    QList<QPointF> paintPointList2;//校区2
    QList<double> timeList;//每段路径时间（不包括跨校区）
    QList<double> timeList2;
    //查询
    QList<QString> list; //存放查询结果
    int searchType;
    int searchPointId;

private slots:
    void changeStatus();

    void on_btn_navi_clicked();

    void on_btn_search_clicked();
};
#endif // MAINWINDOW_H
