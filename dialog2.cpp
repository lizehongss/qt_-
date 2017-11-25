#include "dialog2.h"
#include "ui_dialog2.h"
#include <QPixmap>
#include <QLabel>
#include "widget.h"
#include <QTimer>
#include <QTime>
#include <QString>
#include "dialog.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);

    //QTimer *timer =new QTimer(this);
   // connect(timer,&QTimer::timeout,this,&Dialog2::timerUpate);
    //timer->start(1000);
}

Dialog2::~Dialog2()
{
    delete ui;
}
 int  Dialog2::a=20;
void Dialog2::on_pushButton_clicked()
{    QFile data("F:\\c++\\try\\demo_one\\data.txt");
    //QFile data("//hotstar//scan_date//date.txt");
     if(data.open(QFile::WriteOnly|QFile::Truncate)){
         QTextStream out(&data);
         out<<"";
     }
    //QMessageBox *msgBox;
    // msgBox = new QMessageBox("支付提示","支付成功",QMessageBox::NoIcon,QMessageBox::Ok );
    QMessageBox::information(NULL,"支付提示","SUCCESS");
   close();
}
/*void Dialog2::timerUpate(){

    a=a-1;
    ui->lcdNumber->display(QString::number(a));
    if(a==0){
        a=20;
        QMessageBox::information(NULL,NULL,"fail");
       // timer->stop();
        close();
        Dialog dlgss;
        if(dlgss.exec()==QDialog::Accepted)show();
    }
}*/
