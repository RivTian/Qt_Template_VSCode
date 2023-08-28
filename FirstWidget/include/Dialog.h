#pragma once
#include <QDebug>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog() { qDebug() << "销毁对话框"; }

private:
    QLineEdit *lineEdit;
    QPushButton *pushButton;

signals:
    void editDone(QString);

private slots:
    void buttonClicked();
};