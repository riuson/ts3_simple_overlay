#include "userdatalistformatter.h"
#include "userdata.h"
#include "userdatalist.h"

UserDataListFormatter::UserDataListFormatter(QObject *parent) :
    QObject(parent)
{
}

QString UserDataListFormatter::formatUserList(const UserDataList *list) const
{
    QString result = QString("<ul>");
    int count = list->count();

    for (int i = 0; i < count; i++) {
        result.append("<li>");
        result.append(this->formatUserData(list->at(i)));
        result.append("</li>");
    }

    result.append("</ul>");

    return result;
}


QString UserDataListFormatter::formatUserData(const UserData *data) const
{
    QString result = QString("%1 %2 %3 %4\n"). \
            arg(data->time().toString("HH:mm:ss")). \
            arg(data->serverName()). \
            arg(data->name()). \
            arg(data->talking());
    return result;
}
