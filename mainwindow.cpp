#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    n = 0;
    m = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    matrix_txt.clear();
    for (int i = 0; i < ui->gridLayout->count(); i++)
    {
       ui->gridLayout->itemAt(i)->widget()->deleteLater();
    }

    QString a = ui->lineEdit->text();
    n = a.toInt();
    QString b = ui->lineEdit_2->text();
    m = b.toInt();

    for(int i = 0; i < n; i++)
    {
        matrix_txt.push_back(QVector<QLineEdit*>());
        for(int j = 0; j< m; j++)
        {
            matrix_txt.back().push_back(new QLineEdit());
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j< m; j++)
        {
            ui->gridLayout->addWidget(matrix_txt[i][j],i,j);
        }
    }

//    QTextEdit *txt1 = new QTextEdit();
//    QTextEdit *txt2 = new QTextEdit();
//    QTextEdit *txt3 = new QTextEdit();
//    ui->gridLayout->addWidget(txt1,0,0);
//    ui->gridLayout->addWidget(txt2,0,1);
//    ui->gridLayout->addWidget(txt3,1,0);
}


void MainWindow::on_pushButton_2_clicked()
{
    matrix_lambda.clear();
    QString a;
    int data;
    for(int i = 0; i < matrix_txt.size(); i++)
    {
        matrix_lambda.push_back(QVector<int>());
        for(int j = 0; j< matrix_txt.back().size(); j++)
        {
            a = matrix_txt[i][j]->text();
            data = a.toInt();
            matrix_lambda.back().push_back(data);
        }
    }

//    for(int i = 0; i < matrix_lambda.size(); i++)
//    {
//        for(int j = 0; j< matrix_lambda.back().size(); j++)
//        {
//            qDebug() << matrix_lambda[i][j];
//        }
//    }


}


