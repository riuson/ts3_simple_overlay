#include "formoverlay.h"
#include "ui_formoverlay.h"

#include <QDateTime>
#include <QTimer>
#include "../../classes/userdata.h"
#include "../../classes/userdatalist.h"

FormOverlay::FormOverlay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormOverlay)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = this->windowFlags();
    flags = Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint;
    flags |= Qt::WindowStaysOnTopHint;
    this->setWindowFlags(flags);

    // transparent window
    //setStyleSheet("background:transparent;");
    //setAttribute(Qt::WA_TranslucentBackground);
    //setWindowFlags(flags | Qt::FramelessWindowHint);

    this->mUsers = new UserDataList(this);

    this->mTimer = new QTimer(this);
    this->connect(this->mTimer, SIGNAL(timeout()), SLOT(updateDisplay()));
    this->mTimer->start(1000);
}

FormOverlay::~FormOverlay()
{
    this->mTimer->stop();

    delete ui;

    delete this->mUsers;
    this->mUsers = NULL;
}

void FormOverlay::clientTalk(UserData *data)
{
    this->mUsers->append(data);

    this->updateDisplay();
}

void FormOverlay::updateDisplay()
{
    this->mUsers->cleanUp(5000);

    int count = this->mUsers->count();
    QString result = QString("<ul>");

    for (int i = 0; i < count; i++) {
        result.append("<li>");
        result.append(this->formatUserData(this->mUsers->at(i)));
        result.append("</li>");
    }

    result.append("</ul>");

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
