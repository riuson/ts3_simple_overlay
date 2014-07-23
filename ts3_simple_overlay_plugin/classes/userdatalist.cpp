#include "userdatalist.h"
#include "userdata.h"

UserDataList::UserDataList(QObject *parent) :
    QObject(parent)
{
}

UserDataList::~UserDataList()
{
    qDeleteAll(this->mList);
}

int UserDataList::count() const
{
    return this->mList.count();
}

void UserDataList::append(UserData *data)
{
    this->mList.append(data);
}

const UserData *UserDataList::at(int index) const
{
    return this->mList.at(index);
}
