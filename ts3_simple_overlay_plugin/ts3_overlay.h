#ifndef TS3_OVERLAY_H
#define TS3_OVERLAY_H

#include "ts3_overlay_global.h"
#include "includes/public_definitions.h"
#include "includes/ts3_functions.h"

class QLabel;
class QWidget;

class Ts3_overlay
{
public:
    Ts3_overlay();
    ~Ts3_overlay();

    void showOverlay();
    void hideOverlay();

    void runSettings(void *parent = NULL);

    void setFunctionPointers(const struct TS3Functions funcs);
    void onTalkStatusChangeEvent(quint64 serverConnectionHandlerID, qint32 status, qint32 isReceivedWhisper, anyID clientID);

private:
    QLabel *mLabelTest;
    TS3Functions mTS3Funcs;
};

#endif // TS3_OVERLAY_H
