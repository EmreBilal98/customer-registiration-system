#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

bool MainWindow::openDatabaseFile()
{
    bool control=false;
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/db/mydb.sqlite");
    if(db.open())
        control=true;

    return control;

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_RegisterButton_clicked()
{
    QString name,surname,username,a_number,c_number,iban,password,bank;
    double balance=0.0;
    static int id=1;
    name=ui->name->text();
    surname=ui->surname->text();
    username=ui->username->text();
    a_number=ui->a_number->text();
    c_number=ui->c_number->text();
    iban=ui->iban->text();
    bank=ui->bank->currentText();
    password=ui->password->text();








    if(openDatabaseFile()){
        QSqlQuery qry;
        //QString test="select * from bankUser";
        qry.prepare("INSERT INTO bankUser("
                    "id,"
                    "name,"
                    "surname,"
                    "username,"
                    "accountNumber,"
                    "iban,"
                    "customerNumber,"
                    "balance,"
                    "password,"
                    "bank) "
                    "VALUES(?,?,?,?,?,?,?,?,?,?);");




        qry.addBindValue(id);
        qry.addBindValue(name);
        qry.addBindValue(surname);
        qry.addBindValue(username);
        qry.addBindValue(a_number);
        qry.addBindValue(iban);
        qry.addBindValue(c_number);
        qry.addBindValue(balance);
        qry.addBindValue(password);
        qry.addBindValue(bank);
        id++;

        if(qry.exec())
            QMessageBox::information(this,"info","success");
        else
            QMessageBox::information(this,"info","unsuccess!!!");
    }
    else
        QMessageBox::information(this,"info","cant opened!!!");



}

