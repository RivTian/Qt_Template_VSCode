#pragma once
#include <QObject>

class UserInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
    explicit UserInfo(QString userName) : m_userName(userName){};
    QString userName() const;
    void setUserName(QString userName);

signals:
    void userNameChanged(QString);

private:
    QString m_userName;
};