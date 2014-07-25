#include "formoverlay.h"
#include "ui_formoverlay.h"

#include <QDateTime>
#include <QTimer>
#include <QTextDocument>
#include <QLabel>
#include <QColor>
#include <QPalette>
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

    this->mDocument = new QTextDocument;

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

    delete this->mDocument;
    this->mDocument = NULL;
}

void FormOverlay::clientTalk(UserData *data)
{
    this->mUsers->append(data);

    this->updateDisplay();
}

void FormOverlay::updateDisplay()
{
    this->mUsers->cleanUp(5000);

    QString html = this->mFormatter->formatUserList(this->mUsers);
    QString css = this->mFormatter->getStyle();

    this->displayHtmlCss(html, css);
}

void FormOverlay::displayHtmlCss(const QString &html, const QString &css)
{
    this->mDocument->clear();

    this->mDocument->addResource(QTextDocument::StyleSheetResource, QUrl("style.css"), css);
    this->mDocument->setHtml(html);

#if 0
    // create transparent color
    QColor transparent (255, 255, 255);
    transparent.setAlpha (0);

    this->ui->textBrowser->viewport()->setAutoFillBackground(false);
    QPalette palette = this->ui->textBrowser->palette();
    palette.setColor(QPalette::Window, transparent);
    this->ui->textBrowser->setPalette(palette);
    this->ui->textBrowser->setAttribute(Qt::WA_TranslucentBackground);
#else // alternative
    this->ui->textBrowser->viewport()->setAutoFillBackground(false);
    this->ui->textBrowser->setAttribute(Qt::WA_TranslucentBackground);
#endif

    this->ui->textBrowser->setDocument(this->mDocument);
    //this->ui->textBrowser->setPlainText(html);
}
