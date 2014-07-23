#include "userdata.h"

UserData::UserData(QObject *parent) :
    QObject(parent)
{
    this->setName(QString());
    this->setTime(QDateTime::currentDateTime());
}

UserData::~UserData()
{
}

QString UserData::name() const
{
    return this->mName;
}

void UserData::setName(const QString &name)
{
    this->mName = name;
}

QDateTime UserData::time() const
{
    return this->mTime;
}

void UserData::setTime(const QDateTime &time)
{
    this->mTime = time;
}

bool UserData::talking() const
{
    return this->mTalking;
}

void UserData::setTalking(bool value)
{
    this->mTalking = value;
}
