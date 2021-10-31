#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <string>
#include <calcu/Operand.h>
#include <calcu/Expression.h>
#include <calcu/SimStack.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    bool isfile=false;
    void initKeybored();
    std::string transformStdExpression(QString expression);
    QString cal(QString s);
};
#endif // MAINWINDOW_H
