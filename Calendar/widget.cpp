#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Memory Compent");
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        this->close();
    });
    QFile file("things.txt");
            file.open(QIODevice::ReadOnly);
            QTextCodec *codec=QTextCodec::codecForName("utf-8");
             QByteArray array;
             array=file.readAll();
             ui->textEdit->setText(codec->toUnicode(array));
             file.close();
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){
        updatetime();
    });
//   connect(timer,&QTimer::timeout,[=](){
//
//    });
     timer->start(100);
     connect(ui->pushButton,&QPushButton::clicked,[=](){
         Myadd=new add();
         Myadd->show();
         connect(Myadd,&add::updatetextedit,[=](){
             updatetext();
         });
     });
     connect(ui->pushButton_3,&QPushButton::clicked,[=](){
               dlt=new delmemo();
               dlt->show();
               connect(dlt,&delmemo::deltextedit,[=](){
                   updatetext();
               });

     });
     ui->textEdit->setReadOnly(true);
     ui->textEdit->setStyleSheet("background-color:transparent;");
//     ui->pushButton->setFlat(true);
//     ui->pushButton->setStyleSheet("QPushButton{border:none;background:transparent;}");
     ui->pushButton->setStyleSheet("background-color: rgb(240, 250, 253);");
     ui->pushButton_2->setStyleSheet("background-color: rgb(235, 247, 250);");
     ui->pushButton_3->setStyleSheet("background-color: rgb(235, 247, 250);");
     setFixedSize(this->width(),this->height());
}

Widget::~Widget()
{
    delete ui;

}
void Widget::updatetime(){

        QDateTime time = QDateTime::currentDateTime();

        QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");

        ui->dateTime->setText(str);
}
void Widget::updatetext(){
            QFile file("things.txt");
            file.open(QIODevice::ReadOnly);
            QTextCodec *codec=QTextCodec::codecForName("utf-8");
             QByteArray array;
             array=file.readAll();
             ui->textEdit->setText(codec->toUnicode(array));
             file.close();
}
void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Calendar/back2.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
