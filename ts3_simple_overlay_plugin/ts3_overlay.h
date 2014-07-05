#ifndef TS3_OVERLAY_H
#define TS3_OVERLAY_H

#include "ts3_overlay_global.h"

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

private:
    QLabel *mLabelTest;
};

#endif // TS3_OVERLAY_H
