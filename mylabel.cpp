#include <QPen>
#include <QDebug>
#include <QPainter>
#include "mylabel.h"
MyLabel::MyLabel(QWidget *parent) :
    QLabel(parent)
{
	i=0;
	j=0;
	show_count=0;
	hum_count=0;	
}

MyLabel::~MyLabel() 
{
}
void MyLabel::paintEvent(QPaintEvent *event)
{
	
	int j=0;
	QPainterPath *painterPath,*painterPath_hum;
	painterPath = new QPainterPath;
	painterPath_hum = new QPainterPath;
	
	if(show_count < 720)
	for(j =0;j < temp_count;j ++)
	{        
		if(j==0)
		{
			painterPath->moveTo(75,(276-(int)show_buf_temp[j]*200/100));
			painterPath_hum->moveTo(75,(276-(int)show_buf_hum[j]*200/100));
		}
		else{
	       painterPath->lineTo(75 + (j),276-(int)show_buf_temp[j]*200/100);
	       painterPath_hum->lineTo(75 + (j),276-(int)show_buf_hum[j]*200/100);
	      }
	}
	
	else{
				for(j = 0;j < 720;j ++)
				{
					if(j==0)
					{
						painterPath->moveTo(75,(276-(int)show_buf_temp[j]*200/100));
						painterPath_hum->moveTo(75,(276-(int)show_buf_hum[j]*200/100));
					}else{
						painterPath->lineTo(75 + (j),276- show_buf_temp[(temp_count+j)%720]*200/100);
						painterPath_hum->lineTo(75 + (j),276- show_buf_hum[(temp_count+j)%720]*200/100);
					}	        
				}
      }
      
  QPainter painter(this);
	QPen pen(QColor(255,67,0),3);
	QPen pen_blue(QColor(0,255,0),3);
	painter.setPen(pen);
	painter.drawPath(*painterPath);
	painter.setPen(pen_blue);
	painter.drawPath(*painterPath_hum);
     temp_count++;   
     if(show_count < 720)                
			show_count ++;
			
	delete painterPath;
	delete painterPath_hum;
}
