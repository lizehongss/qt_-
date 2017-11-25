#include "dialog.h"
#include "ui_dialog.h"
#include "dialog2.h"
#include <QtXml>
#include <QFile>
#include <QDebug>
#include <QListWidget>
#include <QMessageBox>
#include <QFileInfo>
#include <QString>
#include <QTableWidget>
#include <QHeaderView>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    //ui->tableWidget->setRowCount(NumOfReg);
    /* 设置 tableWidget */
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "编号 " << "商品名称" << "价格" << "数量" << "总价");
    ui->tableWidget->verticalHeader()->setVisible(false); // 隐藏水平header
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setColumnWidth(0,200);
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(2,200);
    ui->tableWidget->setColumnWidth(3,200);
    ui->tableWidget->setColumnWidth(4,200);
//-------------------------------------------------------------------------
    QDomDocument doc;
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml",
                                "version=\"1.0\" encoding=\"UTF-8\"");
     doc.appendChild(instruction);
     QDomElement root = doc.createElement("book");
     doc.appendChild(root);
      // 添加第一个元素及其子元素
       QDomElement book = doc.createElement("li");
       QDomAttr id = doc.createAttribute("id");
       QDomElement title = doc.createElement("product_name");
       QDomElement author = doc.createElement("price");
       QDomText text;
       id.setValue(QString("6903944350887"));
       book.setAttributeNode(id);
       text = doc.createTextNode("饼干");
       title.appendChild(text);
       text = doc.createTextNode("11.5");
       author.appendChild(text);
       book.appendChild(title);
       book.appendChild(author);
       root.appendChild(book);

       // 添加第二个元素及其子元素
       book = doc.createElement("li");
       id = doc.createAttribute("id");
       title = doc.createElement("product_name");
       author = doc.createElement("price");
       id.setValue(QString("6923450656181"));
       book.setAttributeNode(id);
       text = doc.createTextNode("牛奶");
       title.appendChild(text);
       text = doc.createTextNode("5.3");
       author.appendChild(text);
       book.appendChild(title);
       book.appendChild(author);
       root.appendChild(book);
       //three
       book = doc.createElement("li");
       id = doc.createAttribute("id");
       title = doc.createElement("product_name");
       author = doc.createElement("price");
       id.setValue(QString("6921168509256"));
       book.setAttributeNode(id);
       text = doc.createTextNode("水");
       title.appendChild(text);
       text = doc.createTextNode("3.0");
       author.appendChild(text);
       book.appendChild(title);
       book.appendChild(author);
       root.appendChild(book);
       //four
       book = doc.createElement("li");
       id = doc.createAttribute("id");
       title = doc.createElement("product_name");
       author = doc.createElement("price");
       id.setValue(QString("6901285991219"));
       book.setAttributeNode(id);
       text = doc.createTextNode("面包");
       title.appendChild(text);
       text = doc.createTextNode("4.2");
       author.appendChild(text);
       book.appendChild(title);
       book.appendChild(author);
       root.appendChild(book);
       //five
       book = doc.createElement("li");
       id = doc.createAttribute("id");
       title = doc.createElement("product_name");
       author = doc.createElement("price");
       id.setValue(QString("6921294358674"));
       book.setAttributeNode(id);
       text = doc.createTextNode("糖果");
       title.appendChild(text);
       text = doc.createTextNode("30.0");
       author.appendChild(text);
       book.appendChild(title);
       book.appendChild(author);
       root.appendChild(book);
       //six
       book = doc.createElement("li");
       id = doc.createAttribute("id");
       title = doc.createElement("product_name");
       author = doc.createElement("price");
       id.setValue(QString("6939287169411"));
       book.setAttributeNode(id);
       text = doc.createTextNode("口香糖");
       title.appendChild(text);
       text = doc.createTextNode("6.0");
       author.appendChild(text);
       book.appendChild(title);
       book.appendChild(author);
       root.appendChild(book);
       //seven
       book = doc.createElement("li");
       id = doc.createAttribute("id");
       title = doc.createElement("product_name");
       author = doc.createElement("price");
       id.setValue(QString("9787203067955"));
       book.setAttributeNode(id);
       text = doc.createTextNode("seven");
       title.appendChild(text);
       text = doc.createTextNode("7.5");
       author.appendChild(text);
       book.appendChild(title);
       book.appendChild(author);
       root.appendChild(book);
       QFile file_xml("myshop.xml");
       if(!file_xml.open(QIODevice::WriteOnly | QIODevice::Truncate)) return ;
       QTextStream out(&file_xml);
       // 将文档保存到文件，4为子元素缩进字符数
       doc.save(out, 4);
       file_xml.close();

}

Dialog::~Dialog()
{
    delete ui;
}
   qreal Dialog::price=0;
   int  Dialog::j=0;
void Dialog::on_pushButton_clicked()
{
   QFile files("F:\\c++\\try\\demo_one\\data.txt");
    //QFile  files("//hotstar//scan_date//date.txt");
    QStringList lists;
    lists.clear();
    QString nums;

    //读取文件内容
    if (files.open(QIODevice ::ReadOnly | QIODevice ::Text))
    {
       QTextStream textStream(&files);
       QRegExp rx("(\\d+)");
       while (!textStream.atEnd())
       {   rx.indexIn(textStream.readLine());
           lists<<rx.cap(1);
       }

       qDebug()<<lists;

}
    else    //---打开文件失败
    {

       QMessageBox ::information(NULL, NULL, "open file error");
    }

    //----------------------------------------------------------
    QDomDocument doc;

    QFile filexmls("myshop.xml");

    if (!filexmls.open(QIODevice::ReadOnly)) qDebug()<<"file open xml" ;

    if(!doc.setContent(&filexmls)){
       filexmls.close();
       qDebug()<<"file open xml1";
    }

    filexmls.close();

    foreach (nums, lists) {
    QDomElement docElem = doc.documentElement();
    QDomNode n = docElem.firstChild();
    int a=(ui->tableWidget->rowCount());
    int search=1;
    for(int b=0;b<a-1;b++){
        if(nums==(ui->tableWidget->item(b,0)->text())){
            int c=(ui->tableWidget->item(b,3)->text().toInt());
            qreal d=(ui->tableWidget->item(b,4)->text().toDouble());
            qreal m=d/c;
            d=d+m;
            c=c+1;
            QTableWidgetItem *item_maxo = new QTableWidgetItem();
            item_maxo->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);
            item_maxo->setText(QString::number(c));
            ui->tableWidget->setItem(b,3,item_maxo);
            QTableWidgetItem *item_max = new QTableWidgetItem();
            item_max->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);
            item_max->setText(QString::number(d));
            ui->tableWidget->setItem(b,4,item_max);
            search=2;
            d=0;
            break;
        }
    }
    while(!n.isNull())
    {
 if (n.isElement())
        {
            QDomElement e = n.toElement();
            if((e.attribute("id")==nums)&(search==1)){
            ui->tableWidget->setRowCount(j+2);
            QTableWidgetItem *item_maxid = new QTableWidgetItem();
            item_maxid->setText(e.attribute("id"));
            ui->tableWidget->setItem(j,0,item_maxid);
            QDomNodeList list = e.childNodes();
            for (int i=0; i<list.count(); i++)
            {
            QDomNode node = list.at(i);
            if(node.isElement()){
            if((node.toElement().tagName())=="price"){
                     QTableWidgetItem *item_max = new QTableWidgetItem();
                     item_max->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);
                     item_max->setText(node.toElement().text());
                     QTableWidgetItem *item_maxnum = new QTableWidgetItem();
                     item_maxnum->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);
                     item_maxnum->setText("1");
                     QTableWidgetItem *item_maxprice = new QTableWidgetItem();
                     item_maxprice->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);
                     item_maxprice->setText(node.toElement().text());
                     ui->tableWidget->setItem(j,2,item_max);
                     ui->tableWidget->setItem(j,4,item_maxprice);
                     ui->tableWidget->setItem(j,3, item_maxnum);

                    }
            if((node.toElement().tagName())=="product_name"){
                        QTableWidgetItem *item_max = new QTableWidgetItem();
                        item_max->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);
                        item_max->setText(node.toElement().text());
                        ui->tableWidget->setItem(j,1,item_max);
                    }
                }
            }
            j++;
            ui->tableWidget->setRowHeight(j,50);

        }
            }
    n = n.nextSibling();

    }

}

    int g=(ui->tableWidget->rowCount());


    for(int f=0;f<g-1;f++){
          Dialog::price +=(ui->tableWidget->item(f,4)->text().toDouble());
       }
    ui->label->setText(QString::number(Dialog::price));
    lists.clear();
    Dialog::price=0;
    nums="";
    Dialog::j=0;
    ui->pushButton->setEnabled(true);
}



void Dialog::on_pushButton_2_clicked()
{

    close();
    //Dialog2 dlgs;
     //if(dlgs.exec()==QDialog::Accepted)show();
}
