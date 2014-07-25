#ifndef USERDATALISTFORMATTER_H
#define USERDATALISTFORMATTER_H

#include <QObject>

class UserData;
class UserDataList;

class UserDataListFormatter : public QObject
{
    Q_OBJECT
public:
    explicit UserDataListFormatter(QObject *parent = 0);

    QString formatUserList(const UserDataList *list) const;

private:
    QString formatUserData(const UserData *data) const;

signals:

public slots:

};

#endif // USERDATALISTFORMATTER_H
