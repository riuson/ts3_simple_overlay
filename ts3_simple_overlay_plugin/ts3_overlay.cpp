#include "ts3_overlay.h"

#include <QLabel>

Ts3_overlay::Ts3_overlay()
{
    this->mLabelTest = new QLabel();
    this->mLabelTest->show();
}

Ts3_overlay::~Ts3_overlay()
{
    this->mLabelTest->hide();
    delete this->mLabelTest;
    this->mLabelTest = NULL;
}
