#include "add.h"


add::add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
       this->close();

    });
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        writetofile();
        emit updatetextedit();
        this->close();
    });

}

add::~add()
{
    delete ui;
}
void add::writetofile(){         //写入文件函数
    QFile file("things.txt");
    file.open(QIODevice::Append);
    QString str=ui->textEdit->toPlainText();
    QByteArray bytes = str.toUtf8();
    ui->textEdit->clear();
    file.write(bytes);
    file.close();
}
