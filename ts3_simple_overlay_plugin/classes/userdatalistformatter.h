#ifndef USERDATALISTFORMATTER_H
#define USERDATALISTFORMATTER_H

#include <QObject>

class UserData;
class UserDataList;
class QStringList;

class UserDataListFormatter : public QObject
{
    Q_OBJECT
public:
    explicit UserDataListFormatter(QObject *parent = 0);

    QString formatUserList(const UserDataList *list) const;
    QString getStyle() const;

private:
    QString formatUserData(const UserData *data) const;
    QStringList collectServerNames(const UserDataList *list) const;

signals:

public slots:

};

#endif // USERDATALISTFORMATTER_H
