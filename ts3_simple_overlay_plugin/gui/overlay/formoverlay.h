#ifndef FORMOVERLAY_H
#define FORMOVERLAY_H

#include <QWidget>

namespace Ui {
class FormOverlay;
}

class UserDataList;
class UserData;

class FormOverlay : public QWidget
{
    Q_OBJECT

public:
    explicit FormOverlay(QWidget *parent = 0);
    virtual ~FormOverlay();

    void clientTalk(const QString &displayName, bool active);

private:
    Ui::FormOverlay *ui;

    UserDataList *mUsers;

    void displayUsersList();
    QString formatUserData(const UserData *data) const;
};

#endif // FORMOVERLAY_H
