#ifndef USERDATALIST_H
#define USERDATALIST_H

#include <QObject>
#include <QList>

class UserData;

class UserDataList : public QObject
{
    Q_OBJECT
public:
    explicit UserDataList(QObject *parent = 0);
    virtual ~UserDataList();

    int count() const;
    void append(UserData *data);
    const UserData *at(int index) const;

    void cleanUp(qint64 older_than_ms);

private:
    QList<UserData *> mList;

    void replaceEqual(UserData *data);

signals:

public slots:

};

#endif // USERDATALIST_H
