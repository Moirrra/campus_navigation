/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QWidget *widget_nav;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget_nav;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_src1;
    QComboBox *comboBox_src2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_dest1;
    QComboBox *comboBox_dest2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QLineEdit *lineEdit_src;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QLineEdit *lineEdit_dest;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_16;
    QComboBox *comboBox_pass1;
    QComboBox *comboBox_pass2;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QComboBox *comboBox_type;
    QPushButton *btn_navi;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_17;
    QDateTimeEdit *dateTimeEdit_setOut;
    QSpacerItem *horizontalSpacer_11;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_arriveTime;
    QLabel *label_endTime;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_duration;
    QLabel *label_timecost;
    QWidget *widget_19;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_arriveTime_2;
    QLabel *label_totallen;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_7;
    QSpinBox *spinBox;
    QLabel *label_5;
    QSlider *horizontalSlider;
    QWidget *widget_18;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_18;
    QLabel *label_curPos;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_duration_2;
    QLabel *label_mtime;
    QWidget *widget_16;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_11;
    QLabel *label_strategy;
    QWidget *widget_20;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_12;
    QLabel *label_ID;
    QSpacerItem *verticalSpacer;
    QWidget *widget_search;
    QHBoxLayout *horizontalLayout_15;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_10;
    QTabWidget *tabWidget_search;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_9;
    QComboBox *comboBox_pos1;
    QComboBox *comboBox_pos2;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit_logicSearch;
    QWidget *widget_17;
    QVBoxLayout *verticalLayout_8;
    QPushButton *btn_search;
    QWidget *widget_15;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_15;
    QTextBrowser *textBrowser_search;
    QWidget *widget_map;
    QWidget *tab2;
    QHBoxLayout *horizontalLayout_10;
    QTextBrowser *logBrowser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1500, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1500, 1000));
        MainWindow->setMaximumSize(QSize(1500, 1000));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(1500, 1000));
        centralwidget->setMaximumSize(QSize(1500, 1000));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        widget_nav = new QWidget(tab1);
        widget_nav->setObjectName(QStringLiteral("widget_nav"));
        widget_nav->setGeometry(QRect(959, 0, 491, 941));
        verticalLayout_4 = new QVBoxLayout(widget_nav);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tabWidget_nav = new QTabWidget(widget_nav);
        tabWidget_nav->setObjectName(QStringLiteral("tabWidget_nav"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget_nav->sizePolicy().hasHeightForWidth());
        tabWidget_nav->setSizePolicy(sizePolicy1);
        tabWidget_nav->setMinimumSize(QSize(0, 0));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget = new QWidget(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 50));
        widget->setMaximumSize(QSize(16777215, 80));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox_src1 = new QComboBox(widget);
        comboBox_src1->setObjectName(QStringLiteral("comboBox_src1"));

        horizontalLayout->addWidget(comboBox_src1);

        comboBox_src2 = new QComboBox(widget);
        comboBox_src2->setObjectName(QStringLiteral("comboBox_src2"));
        comboBox_src2->setMinimumSize(QSize(180, 0));

        horizontalLayout->addWidget(comboBox_src2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 50));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox_dest1 = new QComboBox(widget_2);
        comboBox_dest1->setObjectName(QStringLiteral("comboBox_dest1"));

        horizontalLayout_2->addWidget(comboBox_dest1);

        comboBox_dest2 = new QComboBox(widget_2);
        comboBox_dest2->setObjectName(QStringLiteral("comboBox_dest2"));
        comboBox_dest2->setMinimumSize(QSize(180, 0));

        horizontalLayout_2->addWidget(comboBox_dest2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(widget_2);

        tabWidget_nav->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_ = new QWidget(tab_2);
        widget_->setObjectName(QStringLiteral("widget_"));
        widget_->setMaximumSize(QSize(16777215, 80));
        horizontalLayout_6 = new QHBoxLayout(widget_);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_9 = new QLabel(widget_);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);

        lineEdit_src = new QLineEdit(widget_);
        lineEdit_src->setObjectName(QStringLiteral("lineEdit_src"));

        horizontalLayout_6->addWidget(lineEdit_src);


        verticalLayout_3->addWidget(widget_);

        widget_8 = new QWidget(tab_2);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMaximumSize(QSize(16777215, 80));
        horizontalLayout_7 = new QHBoxLayout(widget_8);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_10 = new QLabel(widget_8);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_7->addWidget(label_10);

        lineEdit_dest = new QLineEdit(widget_8);
        lineEdit_dest->setObjectName(QStringLiteral("lineEdit_dest"));

        horizontalLayout_7->addWidget(lineEdit_dest);


        verticalLayout_3->addWidget(widget_8);

        tabWidget_nav->addTab(tab_2, QString());

        verticalLayout_4->addWidget(tabWidget_nav);

        widget_9 = new QWidget(widget_nav);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setMaximumSize(QSize(580, 700));
        verticalLayout_7 = new QVBoxLayout(widget_9);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        widget_12 = new QWidget(widget_9);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setMinimumSize(QSize(0, 50));
        widget_12->setMaximumSize(QSize(16777215, 80));
        horizontalLayout_17 = new QHBoxLayout(widget_12);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_16 = new QLabel(widget_12);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMaximumSize(QSize(72, 25));

        horizontalLayout_17->addWidget(label_16);

        comboBox_pass1 = new QComboBox(widget_12);
        comboBox_pass1->setObjectName(QStringLiteral("comboBox_pass1"));
        comboBox_pass1->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_17->addWidget(comboBox_pass1);

        comboBox_pass2 = new QComboBox(widget_12);
        comboBox_pass2->setObjectName(QStringLiteral("comboBox_pass2"));
        comboBox_pass2->setMinimumSize(QSize(180, 0));

        horizontalLayout_17->addWidget(comboBox_pass2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_5);


        verticalLayout_7->addWidget(widget_12);

        widget_3 = new QWidget(widget_9);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 50));
        widget_3->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(12, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        comboBox_type = new QComboBox(widget_3);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox_type->sizePolicy().hasHeightForWidth());
        comboBox_type->setSizePolicy(sizePolicy3);
        comboBox_type->setMinimumSize(QSize(200, 0));

        horizontalLayout_3->addWidget(comboBox_type);

        btn_navi = new QPushButton(widget_3);
        btn_navi->setObjectName(QStringLiteral("btn_navi"));
        btn_navi->setMinimumSize(QSize(95, 0));
        btn_navi->setMaximumSize(QSize(95, 16777215));

        horizontalLayout_3->addWidget(btn_navi);


        verticalLayout_7->addWidget(widget_3);

        widget_13 = new QWidget(widget_9);
        widget_13->setObjectName(QStringLiteral("widget_13"));
        horizontalLayout_11 = new QHBoxLayout(widget_13);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_17 = new QLabel(widget_13);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy2.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy2);

        horizontalLayout_11->addWidget(label_17);

        dateTimeEdit_setOut = new QDateTimeEdit(widget_13);
        dateTimeEdit_setOut->setObjectName(QStringLiteral("dateTimeEdit_setOut"));
        dateTimeEdit_setOut->setMinimumDateTime(QDateTime(QDate(2021, 4, 24), QTime(0, 0, 0)));
        dateTimeEdit_setOut->setCalendarPopup(true);

        horizontalLayout_11->addWidget(dateTimeEdit_setOut);

        horizontalSpacer_11 = new QSpacerItem(95, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);


        verticalLayout_7->addWidget(widget_13);

        widget_14 = new QWidget(widget_9);
        widget_14->setObjectName(QStringLiteral("widget_14"));
        widget_14->setMinimumSize(QSize(0, 60));
        horizontalLayout_12 = new QHBoxLayout(widget_14);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_arriveTime = new QLabel(widget_14);
        label_arriveTime->setObjectName(QStringLiteral("label_arriveTime"));

        horizontalLayout_12->addWidget(label_arriveTime);

        label_endTime = new QLabel(widget_14);
        label_endTime->setObjectName(QStringLiteral("label_endTime"));

        horizontalLayout_12->addWidget(label_endTime);


        verticalLayout_7->addWidget(widget_14);

        widget_6 = new QWidget(widget_9);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(0, 60));
        horizontalLayout_13 = new QHBoxLayout(widget_6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_duration = new QLabel(widget_6);
        label_duration->setObjectName(QStringLiteral("label_duration"));

        horizontalLayout_13->addWidget(label_duration);

        label_timecost = new QLabel(widget_6);
        label_timecost->setObjectName(QStringLiteral("label_timecost"));

        horizontalLayout_13->addWidget(label_timecost);


        verticalLayout_7->addWidget(widget_6);

        widget_19 = new QWidget(widget_9);
        widget_19->setObjectName(QStringLiteral("widget_19"));
        widget_19->setMinimumSize(QSize(0, 60));
        horizontalLayout_20 = new QHBoxLayout(widget_19);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_arriveTime_2 = new QLabel(widget_19);
        label_arriveTime_2->setObjectName(QStringLiteral("label_arriveTime_2"));

        horizontalLayout_20->addWidget(label_arriveTime_2);

        label_totallen = new QLabel(widget_19);
        label_totallen->setObjectName(QStringLiteral("label_totallen"));

        horizontalLayout_20->addWidget(label_totallen);


        verticalLayout_7->addWidget(widget_19);

        widget_4 = new QWidget(widget_9);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        spinBox = new QSpinBox(widget_4);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(20);
        spinBox->setMaximum(150);
        spinBox->setValue(80);

        horizontalLayout_4->addWidget(spinBox);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        horizontalSlider = new QSlider(widget_4);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider);


        verticalLayout_7->addWidget(widget_4);

        widget_18 = new QWidget(widget_9);
        widget_18->setObjectName(QStringLiteral("widget_18"));
        widget_18->setMinimumSize(QSize(0, 50));
        widget_18->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_18 = new QHBoxLayout(widget_18);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_18 = new QLabel(widget_18);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy2.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy2);

        horizontalLayout_18->addWidget(label_18);

        label_curPos = new QLabel(widget_18);
        label_curPos->setObjectName(QStringLiteral("label_curPos"));

        horizontalLayout_18->addWidget(label_curPos);


        verticalLayout_7->addWidget(widget_18);

        widget_7 = new QWidget(widget_9);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMinimumSize(QSize(0, 60));
        horizontalLayout_19 = new QHBoxLayout(widget_7);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_duration_2 = new QLabel(widget_7);
        label_duration_2->setObjectName(QStringLiteral("label_duration_2"));
        label_duration_2->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_19->addWidget(label_duration_2);

        label_mtime = new QLabel(widget_7);
        label_mtime->setObjectName(QStringLiteral("label_mtime"));

        horizontalLayout_19->addWidget(label_mtime);


        verticalLayout_7->addWidget(widget_7);

        widget_16 = new QWidget(widget_9);
        widget_16->setObjectName(QStringLiteral("widget_16"));
        widget_16->setMinimumSize(QSize(0, 50));
        widget_16->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_16 = new QHBoxLayout(widget_16);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_11 = new QLabel(widget_16);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);

        horizontalLayout_16->addWidget(label_11);

        label_strategy = new QLabel(widget_16);
        label_strategy->setObjectName(QStringLiteral("label_strategy"));

        horizontalLayout_16->addWidget(label_strategy);


        verticalLayout_7->addWidget(widget_16);

        widget_20 = new QWidget(widget_9);
        widget_20->setObjectName(QStringLiteral("widget_20"));
        widget_20->setMinimumSize(QSize(0, 50));
        widget_20->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_21 = new QHBoxLayout(widget_20);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_12 = new QLabel(widget_20);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);

        horizontalLayout_21->addWidget(label_12);

        label_ID = new QLabel(widget_20);
        label_ID->setObjectName(QStringLiteral("label_ID"));

        horizontalLayout_21->addWidget(label_ID);


        verticalLayout_7->addWidget(widget_20);


        verticalLayout_4->addWidget(widget_9);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        widget_search = new QWidget(tab1);
        widget_search->setObjectName(QStringLiteral("widget_search"));
        widget_search->setGeometry(QRect(10, 717, 900, 231));
        widget_search->setMinimumSize(QSize(0, 190));
        widget_search->setMaximumSize(QSize(900, 16777215));
        horizontalLayout_15 = new QHBoxLayout(widget_search);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        widget_10 = new QWidget(widget_search);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        verticalLayout_10 = new QVBoxLayout(widget_10);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        tabWidget_search = new QTabWidget(widget_10);
        tabWidget_search->setObjectName(QStringLiteral("tabWidget_search"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tabWidget_search->sizePolicy().hasHeightForWidth());
        tabWidget_search->setSizePolicy(sizePolicy4);
        tabWidget_search->setMinimumSize(QSize(0, 120));
        tabWidget_search->setMaximumSize(QSize(400, 16777215));
        tabWidget_search->setElideMode(Qt::ElideNone);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_9 = new QHBoxLayout(tab_3);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        comboBox_pos1 = new QComboBox(tab_3);
        comboBox_pos1->setObjectName(QStringLiteral("comboBox_pos1"));
        comboBox_pos1->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_9->addWidget(comboBox_pos1);

        comboBox_pos2 = new QComboBox(tab_3);
        comboBox_pos2->setObjectName(QStringLiteral("comboBox_pos2"));

        horizontalLayout_9->addWidget(comboBox_pos2);

        tabWidget_search->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        horizontalLayout_8 = new QHBoxLayout(tab_4);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        lineEdit_logicSearch = new QLineEdit(tab_4);
        lineEdit_logicSearch->setObjectName(QStringLiteral("lineEdit_logicSearch"));

        horizontalLayout_8->addWidget(lineEdit_logicSearch);

        tabWidget_search->addTab(tab_4, QString());

        verticalLayout_10->addWidget(tabWidget_search);

        widget_17 = new QWidget(widget_10);
        widget_17->setObjectName(QStringLiteral("widget_17"));
        sizePolicy3.setHeightForWidth(widget_17->sizePolicy().hasHeightForWidth());
        widget_17->setSizePolicy(sizePolicy3);
        widget_17->setMinimumSize(QSize(140, 0));
        widget_17->setMaximumSize(QSize(140, 200));
        verticalLayout_8 = new QVBoxLayout(widget_17);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        btn_search = new QPushButton(widget_17);
        btn_search->setObjectName(QStringLiteral("btn_search"));

        verticalLayout_8->addWidget(btn_search);


        verticalLayout_10->addWidget(widget_17);


        horizontalLayout_15->addWidget(widget_10);

        widget_15 = new QWidget(widget_search);
        widget_15->setObjectName(QStringLiteral("widget_15"));
        widget_15->setMinimumSize(QSize(400, 150));
        widget_15->setMaximumSize(QSize(450, 16777215));
        verticalLayout_5 = new QVBoxLayout(widget_15);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_15 = new QLabel(widget_15);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_5->addWidget(label_15);

        textBrowser_search = new QTextBrowser(widget_15);
        textBrowser_search->setObjectName(QStringLiteral("textBrowser_search"));

        verticalLayout_5->addWidget(textBrowser_search);


        horizontalLayout_15->addWidget(widget_15);

        widget_map = new QWidget(tab1);
        widget_map->setObjectName(QStringLiteral("widget_map"));
        widget_map->setGeometry(QRect(-20, 9, 981, 691));
        widget_map->setStyleSheet(QStringLiteral(""));
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        horizontalLayout_10 = new QHBoxLayout(tab2);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        logBrowser = new QTextBrowser(tab2);
        logBrowser->setObjectName(QStringLiteral("logBrowser"));

        horizontalLayout_10->addWidget(logBrowser);

        tabWidget->addTab(tab2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_nav->setCurrentIndex(0);
        tabWidget_search->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\214\227\344\272\254\351\202\256\347\224\265\345\244\247\345\255\246\346\240\241\345\233\255\345\257\274\350\210\252", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\207\272\345\217\221\345\234\260\357\274\232", Q_NULLPTR));
        comboBox_src1->clear();
        comboBox_src1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\262\231\346\262\263", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\234\254\351\203\250", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("MainWindow", "\347\233\256\347\232\204\345\234\260\357\274\232", Q_NULLPTR));
        comboBox_dest1->clear();
        comboBox_dest1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\262\231\346\262\263", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\234\254\351\203\250", Q_NULLPTR)
        );
        tabWidget_nav->setTabText(tabWidget_nav->indexOf(tab), QApplication::translate("MainWindow", "\347\211\251\347\220\206\344\275\215\347\275\256", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\345\207\272\345\217\221\345\234\260\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\347\233\256\347\232\204\345\234\260\357\274\232", Q_NULLPTR));
        tabWidget_nav->setTabText(tabWidget_nav->indexOf(tab_2), QApplication::translate("MainWindow", "\351\200\273\350\276\221\344\275\215\347\275\256", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "\351\200\224\345\276\204\345\234\260\357\274\232", Q_NULLPTR));
        comboBox_pass1->clear();
        comboBox_pass1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\262\231\346\262\263", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\234\254\351\203\250", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindow", "\347\255\226\347\225\245\357\274\232", Q_NULLPTR));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\234\200\347\237\255\350\267\235\347\246\273", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\234\200\347\237\255\346\227\266\351\227\264", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\200\224\345\276\204\346\237\220\345\234\260\346\234\200\347\237\255\350\267\235\347\246\273", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\275\277\347\224\250\344\272\244\351\200\232\345\267\245\345\205\267\346\234\200\347\237\255\346\227\266\351\227\264", Q_NULLPTR)
        );
        btn_navi->setText(QApplication::translate("MainWindow", "\345\257\274\350\210\252", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "\345\207\272\345\217\221\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        dateTimeEdit_setOut->setDisplayFormat(QApplication::translate("MainWindow", "yyyy/M/d HH:mm", Q_NULLPTR));
        label_arriveTime->setText(QApplication::translate("MainWindow", "\351\242\204\350\256\241\345\210\260\350\276\276\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_endTime->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_duration->setText(QApplication::translate("MainWindow", "\351\242\204\350\256\241\347\224\250\346\227\266\357\274\232", Q_NULLPTR));
        label_timecost->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_arriveTime_2->setText(QApplication::translate("MainWindow", "\346\200\273\350\267\235\347\246\273\357\274\232", Q_NULLPTR));
        label_totallen->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\255\245\350\241\214\351\200\237\345\272\246\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "m/min", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\344\275\215\347\275\256\357\274\232", Q_NULLPTR));
        label_curPos->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_duration_2->setText(QApplication::translate("MainWindow", "\346\250\241\346\213\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_mtime->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\347\255\226\347\225\245\357\274\232", Q_NULLPTR));
        label_strategy->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\347\224\250\346\210\267\357\274\232", Q_NULLPTR));
        label_ID->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        comboBox_pos1->clear();
        comboBox_pos1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\262\231\346\262\263", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\234\254\351\203\250", Q_NULLPTR)
        );
        tabWidget_search->setTabText(tabWidget_search->indexOf(tab_3), QApplication::translate("MainWindow", "\347\211\251\347\220\206\344\275\215\347\275\256", Q_NULLPTR));
        tabWidget_search->setTabText(tabWidget_search->indexOf(tab_4), QApplication::translate("MainWindow", "\351\200\273\350\276\221\344\275\215\347\275\256", Q_NULLPTR));
        btn_search->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\345\221\250\350\276\271", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "\345\221\250\350\276\271\346\234\215\345\212\241\350\256\276\346\226\275", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("MainWindow", "\344\270\273\351\241\265\351\235\242", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("MainWindow", "\346\227\245\345\277\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
