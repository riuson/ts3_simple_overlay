#ifndef USERDATA_H
#define USERDATA_H

#include <QObject>
#include <QString>
#include <QDateTime>

class UserData : public QObject
{
    Q_OBJECT
public:
    explicit UserData(QObject *parent = 0);
    virtual ~UserData();

    QString name() const;
    void setName(const QString &name);

    QDateTime time() const;
    void setTime(const QDateTime &time);

    bool talking() const;
    void setTalking(bool value);

private:
    QString mName;
    QDateTime mTime;
    bool mTalking;

signals:

public slots:

};

#endif // USERDATA_H
