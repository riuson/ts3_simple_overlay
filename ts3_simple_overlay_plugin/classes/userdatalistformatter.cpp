#include "userdatalistformatter.h"
#include "userdata.h"
#include "userdatalist.h"
#include <QStringList>

UserDataListFormatter::UserDataListFormatter(QObject *parent) :
    QObject(parent)
{
}

QString UserDataListFormatter::formatUserList(const UserDataList *list) const
{
    QString result = QString("<div class='data'>");

    QStringList serverNames = this->collectServerNames(list);

    result += "<ul class='servers'>";

    // servers
    foreach (QString servername, serverNames) {

        result += "<li class='server'>" + servername;

        // users on selected server
        int usersOnServerCount = 0;
        QString usersOnServerFormatted;

        // filter users
        for (int i = 0; i < list->count(); i++) {
            // by selected server
            if (list->at(i)->serverName() == servername) {
                usersOnServerFormatted.append(this->formatUserData(list->at(i)));
                usersOnServerCount++;
            }
        }

        if (usersOnServerCount > 0) {
            result += "<ul class='server_users'>" + usersOnServerFormatted + "</ul>";
        }

        result += "</li>";
    }

    result += "</ul>";

    result.append("</div>");

    result = "<html>"
            "<head>"
            "<link rel='stylesheet' type='text/css' href='style.css'>"
            "</head>"
            "<body>" + result + "</body></html>";
    return result;
}

QString UserDataListFormatter::getStyle() const
{
    QString result = "\
            body {\
                background-color: transparent;\
            }\
            div {\
                background: gainsboro;\
            }\
            \
            ul {\
                margin-bottom: 5px;\
            }\
            \
            li.silent {\
                color: silver;\
            }\
            \
            li.talking {\
                color: green;\
            }\
    ";

    return result;
}


QString UserDataListFormatter::formatUserData(const UserData *data) const
{
    QString result = QString("<li class='%1'>[%2] %3</li>"). \
            arg(data->talking() ? "talking" : "silent" ) . \
            arg(data->time().toString("HH:mm:ss")). \
            arg(data->name())
            ;
    return result;
}

QStringList UserDataListFormatter::collectServerNames(const UserDataList *list) const
{
    QStringList result;

    int count = list->count();

    for (int i = 0; i < count; i++) {
        if (!result.contains(list->at(i)->serverName())) {
            result.append(list->at(i)->serverName());
        }
    }

    return result;
}
