#include "basicdialog.h"
#include "ui_basicdialog.h"

basicdialog::basicdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::basicdialog)
{
    ui->setupUi(this);
}

basicdialog::~basicdialog()
{
    delete ui;
}
