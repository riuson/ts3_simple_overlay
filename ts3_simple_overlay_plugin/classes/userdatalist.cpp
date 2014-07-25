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
    this->replaceEqual(data);
}

const UserData *UserDataList::at(int index) const
{
    return this->mList.at(index);
}

void UserDataList::cleanUp(qint64 older_than_ms)
{
    QDateTime currentTime = QDateTime::currentDateTime();

    // remove old data
    int count = this->mList.count();

    for (int i = count - 1; i >= 0; i--) {
        UserData *data = this->mList.at(i);

        // remove silent users
        if (!data->talking()) {
            // after (older_than_ms) ms of silence
            if (data->time().msecsTo(currentTime) > older_than_ms) {
                this->mList.removeAt(i);
                delete data;
            }
        }
    }
}

void UserDataList::replaceEqual(UserData *data)
{
    // remove old data
    int count = this->mList.count();

    for (int i = count - 1; i >= 0; i--) {
        if (this->mList.at(i)->name() == data->name()) {
            UserData *oldData = this->mList.at(i);
            this->mList.replace(i, data);
            delete oldData;

            return;
        }
    }

    // add new data
    this->mList.append(data);
}
