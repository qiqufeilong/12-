#include <QDebug>
#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QFile>
#include <QDateTime>

#include <unistd.h>
#include <math.h>
#include "api.h"


float show_buf_hum[720];
float show_buf_temp[720];
int temp_count;
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
  ui->setupUi(this);
  QPalette palette1=this->palette();
  palette1.setBrush(QPalette::Window,QBrush(QPixmap(":/images/up_wsn_bg2.jpg")));
  this->setPalette(palette1);
  this->setAutoFillBackground(true);
  
  palette1.setBrush(QPalette::Window,QBrush(QPixmap(":/images/02.jpg")));
  ui->frame_2->setPalette(palette1);
  ui->frame_2->setAutoFillBackground(true);    

  char *ipaddr="192.168.12.248";
  printf("ipaddr%s\n",ipaddr);
  int port=7838;
  cliect_thread = new Cliect();
  cliect_thread->GetConnect(ipaddr,port);
  cliect_thread->start();
  zb_thread = new ZigbeeTopo();

  nd_timer = new QTimer();
  connect(nd_timer,SIGNAL(timeout()),this,SLOT(lcd_display()));
  nd_timer->start(100);
  temp_count=0;
  hum_count=0;
  TempLcdNumber = new QLCDNumber(ui->frame_4);
  TempLcdNumber->setObjectName(QString::fromUtf8("TempLcdNumber"));
  TempLcdNumber->setGeometry(QRect(370, 45, 90, 31));
  TempLcdNumber->setNumDigits(5);
  HumLcdNumber = new QLCDNumber(ui->frame_4);
  HumLcdNumber->setObjectName(QString::fromUtf8("HumLcdNumber"));
  HumLcdNumber->setGeometry(QRect(560, 45, 90, 31));
  HumLcdNumber->setNumDigits(5);
  line = new MyLabel(ui->frame_5);
  line->setGeometry(QRect(0, 0, 720, 322));

}
MainWidget::~MainWidget()
{
 
}

int MainWidget::calc_sth11(float *p_humidity ,float *p_temperature) 
{  
	int ret= 0;

	const float C1=-4.0; // for 12 Bit
	const float C2= 0.0405; // for 12 Bit
	const float C3=-0.0000028; // for 12 Bit
	const float T1=0.01; // for 14 Bit @ 5V
	const float T2=0.00008; // for 14 Bit @ 5V

	float rh=*p_humidity; // rh: Humidity [Ticks] 12 Bit
	float t=*p_temperature; // t: Temperature [Ticks] 14 Bit
	float rh_lin; // rh_lin: Humidity linear
	float rh_true; // rh_true: Temperature compensated humidity
	float t_C; // t_C : Temperature [C]
	t_C=t*0.01 - 42; //calc. Temperature from ticks to [C]
	rh_lin=C3*rh*rh + C2*rh + C1; //calc. Humidity from ticks to [%RH]
	rh_true=(t_C-25)*(T1+T2*rh)+rh_lin; //calc. Temperature compensated humidity [%RH]
	if(rh_true>100)rh_true=100; //cut if the value is outside of
	if(rh_true<0.1)rh_true=0.1; //the physical possible range
	*p_temperature=t_C; //return temperature [C]
	*p_humidity=rh_true; //return humidity[%RH]
	
	if (t_C>0)return ret = 1;
	return ret;	
} 

int MainWidget:: getsht11(char *rData, char *&pTemp, char *&pHumi)
{
		int i=0,j=0;
		float temp,humi;
		uint8 tlen,hlen;
		int calcret=0;
		char Temp_t[16];
		

		i = rData[1] * 256 + rData[0];
    		j = rData[3] * 256 + rData[2];

		
		temp = (float)j;
		humi = (float)i;
		calcret = calc_sth11(&humi,&temp);
		//qDebug("\rtemp=%f\t humi=%f\r",temp,humi);
		if( ((int)temp) > 0  && 0 <= humi <= 100 && calcret) {
			tlen = sprintf(pTemp, "%d.%d",(int)temp,(int)((temp-(int)temp)*10));
			hlen = sprintf(pHumi, "%d.%d",(int)humi,(int)((humi-(int)humi)*10));
			//qDebug("\rTEMP=%s\tHUMI=%s\r",pTemp,pHumi);
			return 1;
		}
		return 0;

}	




void MainWidget::lcd_display(){
char temp[5],humi[5],data[4];
char *pTemp,*pHumi;
pTemp = temp;
pHumi = humi;
int return_t=0;

{
	//qDebug("-----------------MainWidget::lcd_display----------------\n");
	data[0]=BREAK_UINT32( ptemperature,3 );
  data[1]=BREAK_UINT32( ptemperature,2 );
  data[2]=BREAK_UINT32( ptemperature,1 );
  data[3]=BREAK_UINT32( ptemperature,0 );
  return_t=getsht11(data, pTemp, pHumi);
  TempLcdNumber->display((pTemp));
  HumLcdNumber->display((pHumi));

	show_buf_temp[temp_count % 720] =atof(pTemp);  
  show_buf_hum[temp_count % 720] = atof(pHumi);
  //printf("temp_count = %d\n",temp_count);
  //printf("show_buf[%d] = %f,%f\n",temp_count% 720,atof(pTemp),atof(pHumi));
     
  line->update();//更新曲线显示的标签
}


}
