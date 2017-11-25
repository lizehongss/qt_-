#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"
#include <QPalette>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //hide();
    Dialog dlg;

    if(dlg.exec()==QDialog::Accepted)show();
}
