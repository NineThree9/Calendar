#include "MyLabel.h"
MyLabel::MyLabel(QWidget* parent):QLabel(parent) 
{
	this->setMouseTracking(true);
	this->setStyleSheet("QLabel{font-size:20px;}");
	this->setAlignment(Qt::AlignCenter);
};
void MyLabel::enterEvent(QEnterEvent*)
{
	this->setStyleSheet("QLabel{color:rgba(255, 0, 0, 255);font-size:30px;}");
}

//鼠标离开事件
void MyLabel::leaveEvent(QEvent*)
{
	this->setStyleSheet("QLabel{color:rgba(0, 0, 0, 255);font-size:20px;}");
}
