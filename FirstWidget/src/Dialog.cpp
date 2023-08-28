#include "Dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    resize(500, 450);

    lineEdit = new QLineEdit(this);
    pushButton = new QPushButton(this);

    lineEdit->setGeometry(100, 200, 250, 40);
    pushButton->move(380, 205);
    pushButton->setText(tr("send"));

    // 信号连接到槽
    connect(pushButton, QPushButton::clicked, this, buttonClicked);
}

void Dialog::buttonClicked()
{
    emit editDone(lineEdit->text());
    deleteLater();
}