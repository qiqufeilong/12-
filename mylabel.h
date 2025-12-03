#include <QLabel>  
#include "api.h"
#define LINE_NUM 660

class MyLabel : public QLabel
{
	Q_OBJECT
public:
    MyLabel(QWidget *parent = 0);
    ~MyLabel();

protected:

private:

    void paintEvent(QPaintEvent *event);
    int show_count;
    int hum_count;
    int i,j;
};


