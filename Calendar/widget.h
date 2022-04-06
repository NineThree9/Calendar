#ifndef WIDGET_H
#define WIDGET_H
#include"add.h"
#include"delmemo.h"
#include <QWidget>
#include<QPushbutton>
#include<QFile>
#include<QDebug>
#include<QMessageBox>
#include<QByteArray>
#include<QtCore5Compat/QTextCodec>
#include<QTimer>
#include<QPainter>
#include "ui_widget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
   void updatetime();
   void paintEvent(QPaintEvent *event);
   void updatetext();
private:
    Ui::Widget *ui;
    add *Myadd;
    QTimer *timer;
    delmemo* dlt;

};
#endif // WIDGET_H
