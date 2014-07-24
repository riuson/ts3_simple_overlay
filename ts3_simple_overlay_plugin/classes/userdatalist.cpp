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
    // remove old data
    int count = this->mList.count();

    for (int i = count - 1; i >= 0; i--) {
        if (this->mList.at(i)->name() == data->name()) {
            UserData *oldData = this->mList.at(i);
            this->mList.removeAt(i);
            delete oldData;
            this->mList.insert(i, data);

            return;
        }
    }

    // add new data
    this->mList.append(data);
}

const UserData *UserDataList::at(int index) const
{
    return this->mList.at(index);
}
