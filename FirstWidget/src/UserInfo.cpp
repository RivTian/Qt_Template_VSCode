#include"UserInfo.h"

QString UserInfo::userName() const
{
    return m_userName;
}

void UserInfo::setUserName(QString userName)
{
    m_userName = userName;
    emit userNameChanged(userName);
}