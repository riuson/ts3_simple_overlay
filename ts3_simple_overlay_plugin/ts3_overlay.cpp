#include "ts3_overlay.h"

#include <QWidget>
#include <QLabel>
#include <QDialog>
#include <QDateTime>

#include "gui/overlay/formoverlay.h"

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
    this->mOverlay = new FormOverlay();
    this->mOverlay->show();
}

void Ts3_overlay::hideOverlay()
{
    this->mOverlay->hide();
    delete this->mOverlay;
    this->mOverlay = NULL;
}

void Ts3_overlay::runSettings(void *parent)
{
    QDialog dialog((QWidget*)parent);
    dialog.exec();
}

void Ts3_overlay::setFunctionPointers(const TS3Functions funcs)
{
    this->mTS3Funcs = funcs;
}

void Ts3_overlay::onTalkStatusChangeEvent(quint64 serverConnectionHandlerID, qint32 status, qint32 isReceivedWhisper, anyID clientID)
{
    Q_UNUSED(isReceivedWhisper)

    char name[255];
    if (this->mTS3Funcs.getClientDisplayName(serverConnectionHandlerID, clientID, name, sizeof(name)) == 0) {
        QString clientName = QString(name);

        this->mOverlay->clientTalk(clientName, status == 1);
    }
}
