#include "ts3_overlay.h"

#include <QWidget>
#include <QLabel>
#include <QDialog>
#include <QDateTime>

Ts3_overlay::Ts3_overlay()
{
    this->showOverlay();
}

Ts3_overlay::~Ts3_overlay()
{
    this->hideOverlay();
}

void Ts3_overlay::showOverlay()
{
    this->mLabelTest = new QLabel();
    this->mLabelTest->show();
}

void Ts3_overlay::hideOverlay()
{
    this->mLabelTest->hide();
    delete this->mLabelTest;
    this->mLabelTest = NULL;
}

void Ts3_overlay::runSettings(void *parent)
{
    QDialog dialog((QWidget*)parent);
    dialog.exec();
}

void Ts3_overlay::onTalkStatusChangeEvent(quint64 serverConnectionHandlerID, qint32 status, qint32 isReceivedWhisper, quint64 clientID)
{
    QString msg = QString("%1: %2 %3 %4 %5") \
            .arg(QDateTime::currentDateTime().toString()) \
            .arg(serverConnectionHandlerID) \
            .arg(status) \
            .arg(isReceivedWhisper) \
            .arg(clientID);
    this->mLabelTest->setText(msg);
}
