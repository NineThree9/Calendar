#ifndef ADD_H
#define ADD_H

#include <QWidget>
#include<QString>
#include<QTimer>
#include<QDateTime>
#include<QFile>
#include<QDebug>
#include<QMessageBox>
#include<QByteArray>
#include<QtCore5Compat/QTextCodec>
#include<QPushButton>
#include "ui_add.h"
//添加窗口
namespace Ui {
class add;
}

class add : public QWidget
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();
    void writetofile();
signals:
    void updatetextedit();
private:
    Ui::add *ui;

};

#endif // ADD_H
