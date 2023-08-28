#pragma once

#include <QFile>
#include <QWidget>
#include <QCompleter>
#include <QMouseEvent>
#include <QVBoxLayout>
#include "LineEdit.h"
#include "UserInfo.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class FirstWidget;
}
QT_END_NAMESPACE

class FirstWidget : public QWidget
{
    Q_OBJECT

public:
    FirstWidget(QWidget *parent = nullptr);
    ~FirstWidget();
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void buttonClicked();
    void showDialogText(QString text);
    void showUserInfo();

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    LineEdit *lineEdit;
    QVBoxLayout *layout;
    Ui::FirstWidget *ui;
    UserInfo *m_userInfo;
    QFile *qssFile;
};
