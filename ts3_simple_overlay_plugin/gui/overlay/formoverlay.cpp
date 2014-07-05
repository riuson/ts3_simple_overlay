#include "formoverlay.h"
#include "ui_formoverlay.h"

#include <QDateTime>

FormOverlay::FormOverlay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormOverlay)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Tool);
}

FormOverlay::~FormOverlay()
{
    delete ui;
}

void FormOverlay::clientTalk(const QString &displayName, bool active)
{
    if (active) {
        QString msg = QString("%1\n%2") \
                .arg(QDateTime::currentDateTime().toString()) \
                .arg(displayName);

        this->ui->label->setText(msg);
    } else {
        this->ui->label->setText(QString());
    }
}
