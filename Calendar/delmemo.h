#ifndef DELMEMO_H
#define DELMEMO_H
#include <QWidget>
#include<QPushbutton>
#include<QFile>
#include<QDebug>
#include<QMessageBox>
#include<QByteArray>
#include<QtCore5Compat/QTextCodec>
#include<QTimer>
#include "ui_delmemo.h"
//删除窗口
namespace Ui {
class delmemo;
}

class delmemo : public QWidget
{
    Q_OBJECT

public:
    explicit delmemo(QWidget *parent = nullptr);
    ~delmemo();
    void revisememo();
signals:
    void deltextedit();

private:
    Ui::delmemo *ui;
};

#endif // DELMEMO_H
