#include "formoverlay.h"
#include "ui_formoverlay.h"

#include <QDateTime>
#include "../../classes/userdata.h"
#include "../../classes/userdatalist.h"

FormOverlay::FormOverlay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormOverlay)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Tool);
    this->mUsers = new UserDataList(this);
}

FormOverlay::~FormOverlay()
{
    delete ui;

    delete this->mUsers;
    this->mUsers = NULL;
}

void FormOverlay::clientTalk(const QString &displayName, bool active)
{
    UserData *data = new UserData(this);

    data->setName(displayName);
    data->setTime(QDateTime::currentDateTime());
    data->setTalking(active);

    this->mUsers->append(data);

    this->displayUsersList();
}

void FormOverlay::displayUsersList()
{
    int count = this->mUsers->count();
    QString result = QString();

    for (int i = 0; i < count; i++) {
        const UserData *data = this->mUsers->at(i);
        result.append(this->formatUserData(data));
    }

    this->ui->label->setText(result);
}

QString FormOverlay::formatUserData(const UserData *data) const
{
    QString result = QString("%1 %2 %3\n"). \
            arg(data->time().toString("HH:mm:ss")). \
            arg(data->name()). \
            arg(data->talking());
    return result;
}
