/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplication.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATION_H
#define UI_QTWIDGETSAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplicationClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsApplicationClass)
    {
        if (QtWidgetsApplicationClass->objectName().isEmpty())
            QtWidgetsApplicationClass->setObjectName(QString::fromUtf8("QtWidgetsApplicationClass"));
        QtWidgetsApplicationClass->resize(795, 240);
        centralWidget = new QWidget(QtWidgetsApplicationClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 61, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(450, 40, 40, 12));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(500, 31, 104, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(450, 110, 80, 18));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 150, 61, 20));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 110, 80, 18));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 30, 271, 20));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 160, 491, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(423, 60, 71, 20));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(500, 60, 113, 20));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(620, 30, 95, 20));
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(700, 60, 95, 20));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(620, 60, 75, 24));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(350, 30, 75, 24));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(590, 160, 75, 24));
        QtWidgetsApplicationClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(QtWidgetsApplicationClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtWidgetsApplicationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtWidgetsApplicationClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtWidgetsApplicationClass->setStatusBar(statusBar);

        retranslateUi(QtWidgetsApplicationClass);
        QObject::connect(pushButton, SIGNAL(clicked()), QtWidgetsApplicationClass, SLOT(jm()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), QtWidgetsApplicationClass, SLOT(fjm()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), QtWidgetsApplicationClass, SLOT(xz_sr_dz()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), QtWidgetsApplicationClass, SLOT(xz_mm_dz()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), QtWidgetsApplicationClass, SLOT(xz_jg_dz()));

        QMetaObject::connectSlotsByName(QtWidgetsApplicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplicationClass)
    {
        QtWidgetsApplicationClass->setWindowTitle(QCoreApplication::translate("QtWidgetsApplicationClass", "QtWidgetsApplication", nullptr));
        label->setText(QCoreApplication::translate("QtWidgetsApplicationClass", "\346\226\207\344\273\266\345\234\260\345\235\200\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("QtWidgetsApplicationClass", "\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("QtWidgetsApplicationClass", "\345\212\240\345\257\206", nullptr));
        label_3->setText(QCoreApplication::translate("QtWidgetsApplicationClass", "\347\273\223\346\236\234\345\234\260\345\235\200\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("QtWidgetsApplicationClass", "\350\247\243\345\257\206", nullptr));
        label_4->setText(QCoreApplication::translate("QtWidgetsApplicationClass", "\345\257\206\347\240\201\345\234\260\345\235\200\357\274\232", nullptr));
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("QtWidgetsApplicationClass", "\351\200\211\346\213\251\345\234\260\345\235\200", nullptr));
        pushButton_4->setText(QCoreApplication::translate("QtWidgetsApplicationClass", "\351\200\211\346\213\251\345\234\260\345\235\200", nullptr));
        pushButton_5->setText(QCoreApplication::translate("QtWidgetsApplicationClass", "\351\200\211\346\213\251\345\234\260\345\235\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplicationClass: public Ui_QtWidgetsApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION_H
