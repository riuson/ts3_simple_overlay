#ifndef FORMOVERLAY_H
#define FORMOVERLAY_H

#include <QWidget>

namespace Ui {
class FormOverlay;
}

class FormOverlay : public QWidget
{
    Q_OBJECT

public:
    explicit FormOverlay(QWidget *parent = 0);
    ~FormOverlay();

    void clientTalk(const QString &displayName, bool active);

private:
    Ui::FormOverlay *ui;
};

#endif // FORMOVERLAY_H
