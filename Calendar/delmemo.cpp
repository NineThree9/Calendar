#include "delmemo.h"


delmemo::delmemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delmemo)
{
    ui->setupUi(this);
    setWindowTitle("修改");
     QFile file("things.txt");
     file.open(QIODevice::ReadOnly);
     QTextCodec *codec=QTextCodec::codecForName("utf-8");
     QByteArray array;
     array=file.readAll();
     ui->textEdit->setText(codec->toUnicode(array));
     file.close();
     connect(ui->pushButton,&QPushButton::clicked,[=](){
         revisememo();
         emit deltextedit();
         this->close();
     });
     connect(ui->pushButton_2,&QPushButton::clicked,[=](){
         this->close();
     });
}

delmemo::~delmemo()
{
    delete ui;
}
void delmemo::revisememo(){

    QFile file("things.txt");
    file.open(QIODevice::WriteOnly);
    QString str=ui->textEdit->toPlainText();
    QByteArray bytes = str.toUtf8();
    ui->textEdit->clear();
    file.write(bytes);

}
