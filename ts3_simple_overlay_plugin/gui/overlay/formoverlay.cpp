#include "formoverlay.h"
#include "ui_formoverlay.h"

#include <QDateTime>
#include <QTimer>
#include "../../classes/userdata.h"
#include "../../classes/userdatalist.h"
#include "../../classes/userdatalistformatter.h"

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
    this->mFormatter = new UserDataListFormatter(this);

    this->mTimer = new QTimer(this);
    this->connect(this->mTimer, SIGNAL(timeout()), SLOT(updateDisplay()));
    this->mTimer->start(1000);
}

FormOverlay::~FormOverlay()
{
    this->mTimer->stop();

    delete ui;

    delete this->mFormatter;
    this->mFormatter = NULL;

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

    QString formattedList = this->mFormatter->formatUserList(this->mUsers);

    this->ui->label->setText(formattedList);
}
