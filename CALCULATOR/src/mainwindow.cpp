#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font;
    font.setFamily("RetroVille NC");
    font.setPixelSize(ui->plainTextEdit->font().pixelSize());
    ui->plainTextEdit->setFont(font);
    initKeybored();
    this->grabKeyboard();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
        case Qt::Key_Enter:ui->pushButton_equal->click();break;
        case Qt::Key_Return:ui->pushButton_equal->click();break;
        case Qt::Key_Down:ui->plainTextEdit->insertPlainText("\n");break;
        case Qt::Key_0:ui->pushButton_0->click();break;
        case Qt::Key_1:ui->pushButton_1->click();break;
        case Qt::Key_2:ui->pushButton_2->click();break;
        case Qt::Key_3:ui->pushButton_3->click();break;
        case Qt::Key_4:ui->pushButton_4->click();break;
        case Qt::Key_5:ui->pushButton_5->click();break;
        case Qt::Key_6:ui->pushButton_6->click();break;
        case Qt::Key_7:ui->pushButton_7->click();break;
        case Qt::Key_8:ui->pushButton_8->click();break;
        case Qt::Key_9:ui->pushButton_9->click();break;
        case Qt::Key_Period:ui->pushButton_dot->click();break;
        case Qt::Key_Plus:ui->pushButton_plus->click();break;
        case Qt::Key_Minus:ui->pushButton_sub->click();break;
        case Qt::Key_Slash:ui->pushButton_div->click();break;
        case Qt::Key_Asterisk:ui->pushButton_mul->click();break;
        case Qt::Key_AsciiCircum:ui->pushButton_pow->click();break;
        case Qt::Key_NumberSign:ui->pushButton_root->click();break;
        case Qt::Key_Percent:ui->pushButton_mod->click();break;
        case Qt::Key_ParenLeft:ui->pushButton_lb->click();break;
        case Qt::Key_ParenRight:ui->pushButton_rb->click();break;

        case Qt::Key_Left:ui->plainTextEdit->moveCursor(QTextCursor::Left);break;
        case Qt::Key_Right:ui->plainTextEdit->moveCursor(QTextCursor::Right);break;

        case Qt::Key_Backspace:ui->pushButton_back->click();break;
        case Qt::Key_Escape:ui->pushButton_clear->click();break;
   // default:break;
    }
    int key=event->key();
    if((key>=65 && key<=90)||(key>=97 && key<=122))
    {
        ui->plainTextEdit->insertPlainText(event->text());
    }
}

void MainWindow::initKeybored()
{
    //数字0-9、自然对数E、PI、科学记数法e
    connect(ui->pushButton_0,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("0");
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_1,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("1");
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_2,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("2");
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_3,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("3");
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_4,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("4");
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_5,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("5");
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_6,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("6");
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_7,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("7");
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_8,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("8");
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_9,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("9");
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_e,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("E");
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_pi,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("PI");
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_exp,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("e");
        ui->plainTextEdit->setFocus();
    });

    //符号键
    //小数点
    connect(ui->pushButton_dot,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText(".");
        ui->plainTextEdit->setFocus();
    });
    //加号
    connect(ui->pushButton_plus,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("+");
        ui->plainTextEdit->setFocus();
    });
    //减号
    connect(ui->pushButton_sub,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("-");
        ui->plainTextEdit->setFocus();
    });
    //乘号
    connect(ui->pushButton_mul,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("×");
        ui->plainTextEdit->setFocus();
    });
    //除号
    connect(ui->pushButton_div,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("÷");
        ui->plainTextEdit->setFocus();
    });
    //阶乘
    connect(ui->pushButton_fac,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("!");
        ui->plainTextEdit->setFocus();
    });
    //乘方
    connect(ui->pushButton_pow,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("^");
        ui->plainTextEdit->setFocus();
    });
    //开方
    connect(ui->pushButton_root,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("√");
        ui->plainTextEdit->setFocus();
    });
    //左括号
    connect(ui->pushButton_lb,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("(");
        ui->plainTextEdit->setFocus();
    });
    //右括号
    connect(ui->pushButton_rb,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText(")");
        ui->plainTextEdit->setFocus();
    });
    //取余
    connect(ui->pushButton_mod,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("%");
        ui->plainTextEdit->setFocus();
    });

    //三角函数部分
    connect(ui->pushButton_sin,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("sin()");
        ui->plainTextEdit->moveCursor(QTextCursor::Left);
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_cos,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("cos()");
        ui->plainTextEdit->moveCursor(QTextCursor::Left);
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_tan,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("tan()");
        ui->plainTextEdit->moveCursor(QTextCursor::Left);
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_sin_1,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("arcsin()");
        ui->plainTextEdit->moveCursor(QTextCursor::Left);
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_cos_1,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("arccos()");
        ui->plainTextEdit->moveCursor(QTextCursor::Left);
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_tan_1,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("arctan()");
        ui->plainTextEdit->moveCursor(QTextCursor::Left);
        ui->plainTextEdit->setFocus();
    });

    //常用对数lg,自然对数ln
    connect(ui->pushButton_lg,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("lg()");
        ui->plainTextEdit->moveCursor(QTextCursor::Left);
        ui->plainTextEdit->setFocus();
    });
    connect(ui->pushButton_ln,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->insertPlainText("ln()");
        ui->plainTextEdit->moveCursor(QTextCursor::Left);
        ui->plainTextEdit->setFocus();
    });


    //功能键
    //退格键
    connect(ui->pushButton_back,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit->textCursor().deletePreviousChar();
        ui->plainTextEdit->setFocus();
    });
    //清空键
    connect(ui->pushButton_clear,&QAbstractButton::clicked,
            ui->plainTextEdit, [&]{
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setFocus();
    });
    //等号键获取结果
    connect(ui->pushButton_equal,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit_2->clear(); //结果文本框清空
        QString expression = ui->plainTextEdit->toPlainText(); //获取文本框内容
        while(expression.size()>0){ //依次处理多表达式
            QString str = expression.section("\n",0,0); //换行符分隔
            expression = expression.mid(str.size()+1);
            ui->plainTextEdit_2->insertPlainText(cal(str));
            ui->plainTextEdit_2->appendPlainText("");
            ui->plainTextEdit->setFocus();
        }
    });
    //打开文件按钮
    connect(ui->pushButton_file,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        //QString expression = ui->plainTextEdit->toPlainText();
        QFileDialog* f = new QFileDialog(this);
           f->setWindowTitle("Select File*.txt");
           f->setNameFilter("*.txt");
           f->setViewMode(QFileDialog::Detail);

           QString filePath;
           if(f->exec() == QDialog::Accepted)
               filePath = f->selectedFiles()[0];
           QFile file(filePath);
               if(filePath==""){
                   return;
               }
               if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
               {
                   ui->plainTextEdit->appendPlainText("Fail to open file!");
                   return;
               }
               QTextStream readStream(&file);

               isfile = true;
               while(!readStream.atEnd()) //读取文件内容并输出在文本框内
               {
                   QString str = readStream.readLine();
                   str = str.trimmed();
                   ui->plainTextEdit->appendPlainText(str);
               }
    });
    //转换后缀表达式
    connect(ui->pushButton_POSTFIX,&QAbstractButton::clicked,
            ui->plainTextEdit,[&]{
        ui->plainTextEdit_2->clear(); //结果文本框清空
        QString expression = ui->plainTextEdit->toPlainText(); //获取文本框内容
        while(expression.size()>0){ //依次处理多表达式
            QString str = expression.section("\n",0,0); //换行符分隔
            expression = expression.mid(str.size()+1);
            ui->plainTextEdit_2->insertPlainText(postfix(str));
            ui->plainTextEdit_2->appendPlainText("");
            ui->plainTextEdit->setFocus();
        }
    });


}

std::string MainWindow::transformStdExpression(QString expression) //将表达式中的特殊字符转换
{
    expression = expression.replace("×", "*").replace("÷", "/").replace("√", "#").replace("\n","");
    return expression.toStdString();
}

QString MainWindow::cal(QString s)  //调用Expression.cpp进行计算
{
    QString temp;
    Expression expression(transformStdExpression(s));
    try
    {
        temp=QString::number(expression.getres(),'g', 12);
    }catch(std::runtime_error e){
        QMessageBox messagebox(QMessageBox::Warning,"错误",QString::fromStdString(e.what()));
        messagebox.exec();
        temp = "Error";
    }
    return temp;
}

QString MainWindow::postfix(QString s)
{
    QString temp;
    Expression expression(transformStdExpression(s));
    try
    {
        expression.getres();
        temp = QString::fromStdString(expression.postfix());
    }catch(std::runtime_error e){
        QMessageBox messagebox(QMessageBox::Warning,"错误",QString::fromStdString(e.what()));
        messagebox.exec();
        temp = "Error";
    }
    return temp;
}

