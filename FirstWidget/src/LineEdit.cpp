#include "LineEdit.h"

void LineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "在 LineEdit::keyPressEvent() 中处理按下的键：" << event->key();
    QLineEdit::keyPressEvent(event);
    // 让父级接着处理事件
    event->ignore();
}

bool LineEdit::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        qDebug() << "在 LineEdit::type() 中处理 keyPressEvent";
    }
    return QLineEdit::event(event);
}