#ifndef BASICDIALOG_H
#define BASICDIALOG_H

#include <QDialog>

namespace Ui {
class basicdialog;
}

class basicdialog : public QDialog
{
    Q_OBJECT

public:
    explicit basicdialog(QWidget *parent = 0);
    ~basicdialog();

private:
    Ui::basicdialog *ui;
};

#endif // BASICDIALOG_H
