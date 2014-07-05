#include "ts3_overlay.h"

#include <QWidget>
#include <QLabel>
#include <QDialog>

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
