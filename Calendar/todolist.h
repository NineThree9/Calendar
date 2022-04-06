#pragma once
#pragma execution_character_set("utf-8")
#include <QWidget>
#include<string>
#include<QTimer>
#include<fstream>
#include<istream>
#include<QMessageBox>
#include<QString>
#include "ui_todolist.h"
using namespace std;
class QtWidgetsClass : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsClass(QWidget *parent = Q_NULLPTR);
	~QtWidgetsClass();
	const int NumOfTaskSum = 8;//最大任务数
	QString Tast[8];//储存字符
	int NumOfTaskTemp=1;//总共的任务数量
	void UpDate();//更新状态
	void UpDateLabelToTask();//从label更新到数组
	ifstream TastFileIn;
	ofstream TastFileOut;
public slots:
	void add();//添加任务
	void check();//检查是否需要删除,并上移
	
private:
	Ui::QtWidgetsClass ui;
};
