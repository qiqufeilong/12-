#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QSignalMapper>
#include <QList>
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>
#include <QtGui/QLCDNumber>
#include "zigbeetopo.h"
#include "mylabel.h"
#include"cliect_td.h"

namespace Ui {
    class MainWidget;
}
typedef signed   char   int8;
typedef unsigned char   uint8;
typedef unsigned char   byte;
typedef signed   short  int16;
typedef unsigned short  uint16;

typedef signed   long   int32;
typedef unsigned long   uint32;
#define BREAK_UINT32( var, ByteNum ) \
          (byte)((uint32)(((var) >>((ByteNum) * 8)) & 0x00FF))


class MainWidget : public QWidget {
    Q_OBJECT
public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();


private:
    
    int show_count;
    int hum_count;
    
  
public slots:
    void lcd_display();

public:
    Ui::MainWidget *ui;
    int calc_sth11(float *p_humidity ,float *p_temperature);
    int getsht11(char *rData, char *&pTemp, char *&pHumi);
    QTimer *nd_timer;
    QLCDNumber *TempLcdNumber;
    QLCDNumber *HumLcdNumber;
    MyLabel *line;
 
    ZigbeeTopo *zb_thread;
     Cliect *cliect_thread;

};

#endif // MAINWIDGET_H
