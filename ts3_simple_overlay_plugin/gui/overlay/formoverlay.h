#ifndef FORMOVERLAY_H
#define FORMOVERLAY_H

#include <QWidget>

namespace Ui {
class FormOverlay;
}

class QTimer;
class QTextDocument;
class UserData;
class UserDataList;
class UserDataListFormatter;

class FormOverlay : public QWidget
{
    Q_OBJECT

public:
    explicit FormOverlay(QWidget *parent = 0);
    virtual ~FormOverlay();

    void clientTalk(UserData *data);

private:
    Ui::FormOverlay *ui;

    QTimer *mTimer;
    UserDataList *mUsers;
    UserDataListFormatter *mFormatter;
    QTextDocument *mDocument;

private slots:
    void updateDisplay();
    void displayHtmlCss(const QString &html, const QString &css);
};

#endif // FORMOVERLAY_H
