/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created: Fri Mar 16 05:49:24 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QFrame *frame_2;
    QFrame *frame_4;
    QLabel *blue_state;
    QLabel *blue_state_value;
    QLabel *blue_temp;
    QLabel *blue_hum;
    QLabel *blue_sensor;
    QLabel *blue_sensor_value;
    QLabel *blue_temp_2;
    QLabel *blue_hum_2;
    QFrame *frame_5;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(800, 480);
        MainWidget->setStyleSheet(QString::fromUtf8(""));
        frame_2 = new QFrame(MainWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(14, 60, 772, 407));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(0, 0, 772, 78));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        blue_state = new QLabel(frame_4);
        blue_state->setObjectName(QString::fromUtf8("blue_state"));
        blue_state->setGeometry(QRect(15, 45, 70, 31));
        QFont font;
        font.setPointSize(16);
        blue_state->setFont(font);
        blue_state_value = new QLabel(frame_4);
        blue_state_value->setObjectName(QString::fromUtf8("blue_state_value"));
        blue_state_value->setGeometry(QRect(70, 45, 60, 31));
        blue_state_value->setFont(font);
        blue_temp = new QLabel(frame_4);
        blue_temp->setObjectName(QString::fromUtf8("blue_temp"));
        blue_temp->setGeometry(QRect(330, 45, 60, 31));
        blue_temp->setFont(font);
        blue_hum = new QLabel(frame_4);
        blue_hum->setObjectName(QString::fromUtf8("blue_hum"));
        blue_hum->setGeometry(QRect(500, 45, 60, 31));
        blue_hum->setFont(font);
        blue_sensor = new QLabel(frame_4);
        blue_sensor->setObjectName(QString::fromUtf8("blue_sensor"));
        blue_sensor->setGeometry(QRect(130, 45, 116, 31));
        blue_sensor->setFont(font);
        blue_sensor_value = new QLabel(frame_4);
        blue_sensor_value->setObjectName(QString::fromUtf8("blue_sensor_value"));
        blue_sensor_value->setGeometry(QRect(250, 45, 60, 31));
        blue_sensor_value->setFont(font);
        blue_temp_2 = new QLabel(frame_4);
        blue_temp_2->setObjectName(QString::fromUtf8("blue_temp_2"));
        blue_temp_2->setGeometry(QRect(460, 45, 18, 31));
        blue_temp_2->setFont(font);
        blue_hum_2 = new QLabel(frame_4);
        blue_hum_2->setObjectName(QString::fromUtf8("blue_hum_2"));
        blue_hum_2->setGeometry(QRect(650, 45, 15, 31));
        blue_hum_2->setFont(font);
        frame_5 = new QFrame(frame_2);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(0, 84, 772, 322));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0, QApplication::UnicodeUTF8));
        blue_state->setText(QString());
        blue_state_value->setText(QString());
        blue_temp->setText(QApplication::translate("MainWidget", "\346\270\251\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        blue_hum->setText(QApplication::translate("MainWidget", "\346\271\277\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        blue_sensor->setText(QApplication::translate("MainWidget", "\344\274\240\346\204\237\345\231\250\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        blue_sensor_value->setText(QApplication::translate("MainWidget", "SHT11", 0, QApplication::UnicodeUTF8));
        blue_temp_2->setText(QApplication::translate("MainWidget", "\342\204\203", 0, QApplication::UnicodeUTF8));
        blue_hum_2->setText(QApplication::translate("MainWidget", "%", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
