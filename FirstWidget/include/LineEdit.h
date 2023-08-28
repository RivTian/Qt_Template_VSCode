#pragma once
#include <QLineEdit>
#include <QKeyEvent>
#include <QDebug>

class LineEdit : public QLineEdit
{
    Q_OBJECT

public:
    using QLineEdit::QLineEdit;
    bool event(QEvent *event);

protected:
    void keyPressEvent(QKeyEvent *event);
};