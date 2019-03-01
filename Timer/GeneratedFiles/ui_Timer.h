/********************************************************************************
** Form generated from reading UI file 'Timer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMER_H
#define UI_TIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimerClass
{
public:
    QAction *about;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *project_name;
    QLabel *label_2;
    QLineEdit *detail;
    QLabel *label_3;
    QLineEdit *author;
    QHBoxLayout *horizontalLayout;
    QPushButton *start;
    QPushButton *pause;
    QPushButton *finish;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *new_2;
    QPushButton *import_2;
    QPushButton *save;
    QLCDNumber *time_counter;
    QLabel *label_4;
    QTextBrowser *log;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *export_2;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TimerClass)
    {
        if (TimerClass->objectName().isEmpty())
            TimerClass->setObjectName(QString::fromUtf8("TimerClass"));
        TimerClass->resize(318, 541);
        about = new QAction(TimerClass);
        about->setObjectName(QString::fromUtf8("about"));
        centralWidget = new QWidget(TimerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        project_name = new QLineEdit(centralWidget);
        project_name->setObjectName(QString::fromUtf8("project_name"));

        verticalLayout->addWidget(project_name);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        detail = new QLineEdit(centralWidget);
        detail->setObjectName(QString::fromUtf8("detail"));

        verticalLayout->addWidget(detail);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        author = new QLineEdit(centralWidget);
        author->setObjectName(QString::fromUtf8("author"));

        verticalLayout->addWidget(author);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));

        horizontalLayout->addWidget(start);

        pause = new QPushButton(centralWidget);
        pause->setObjectName(QString::fromUtf8("pause"));

        horizontalLayout->addWidget(pause);

        finish = new QPushButton(centralWidget);
        finish->setObjectName(QString::fromUtf8("finish"));

        horizontalLayout->addWidget(finish);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        new_2 = new QPushButton(centralWidget);
        new_2->setObjectName(QString::fromUtf8("new_2"));

        horizontalLayout_2->addWidget(new_2);

        import_2 = new QPushButton(centralWidget);
        import_2->setObjectName(QString::fromUtf8("import_2"));

        horizontalLayout_2->addWidget(import_2);

        save = new QPushButton(centralWidget);
        save->setObjectName(QString::fromUtf8("save"));

        horizontalLayout_2->addWidget(save);


        verticalLayout->addLayout(horizontalLayout_2);

        time_counter = new QLCDNumber(centralWidget);
        time_counter->setObjectName(QString::fromUtf8("time_counter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(time_counter->sizePolicy().hasHeightForWidth());
        time_counter->setSizePolicy(sizePolicy);
        time_counter->setMinimumSize(QSize(300, 100));

        verticalLayout->addWidget(time_counter);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        log = new QTextBrowser(centralWidget);
        log->setObjectName(QString::fromUtf8("log"));

        verticalLayout->addWidget(log);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        export_2 = new QPushButton(centralWidget);
        export_2->setObjectName(QString::fromUtf8("export_2"));

        horizontalLayout_3->addWidget(export_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        TimerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TimerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 318, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        TimerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TimerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TimerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TimerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TimerClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(about);

        retranslateUi(TimerClass);

        QMetaObject::connectSlotsByName(TimerClass);
    } // setupUi

    void retranslateUi(QMainWindow *TimerClass)
    {
        TimerClass->setWindowTitle(QApplication::translate("TimerClass", "Timer", nullptr));
        about->setText(QApplication::translate("TimerClass", "\344\275\234\350\200\205", nullptr));
        label->setText(QApplication::translate("TimerClass", "\351\241\271\347\233\256\345\220\215\347\247\260", nullptr));
        project_name->setText(QString());
        label_2->setText(QApplication::translate("TimerClass", "\345\275\223\345\211\215\345\267\245\344\275\234\345\244\207\346\263\250", nullptr));
        label_3->setText(QApplication::translate("TimerClass", "\344\275\234\350\200\205", nullptr));
        start->setText(QApplication::translate("TimerClass", "\345\274\200\345\247\213", nullptr));
        pause->setText(QApplication::translate("TimerClass", "\346\232\202\345\201\234", nullptr));
        finish->setText(QApplication::translate("TimerClass", "\347\273\223\346\235\237", nullptr));
        new_2->setText(QApplication::translate("TimerClass", "\346\226\260\345\273\272", nullptr));
        import_2->setText(QApplication::translate("TimerClass", "\345\257\274\345\205\245", nullptr));
        save->setText(QApplication::translate("TimerClass", "\345\255\230\346\241\243", nullptr));
        label_4->setText(QApplication::translate("TimerClass", "\345\267\245\344\275\234\346\227\245\345\277\227", nullptr));
        export_2->setText(QApplication::translate("TimerClass", "\345\257\274\345\207\272\346\227\245\345\277\227", nullptr));
        menu->setTitle(QApplication::translate("TimerClass", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimerClass: public Ui_TimerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMER_H
