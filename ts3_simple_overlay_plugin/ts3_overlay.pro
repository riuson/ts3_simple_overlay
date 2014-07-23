#-------------------------------------------------
#
# Project created by QtCreator 2014-07-05T13:52:50
#
#-------------------------------------------------

QT       += widgets

TARGET = ts3_simple_overlay
TEMPLATE = lib

DEFINES += TS3_OVERLAY_LIBRARY

SOURCES += ts3_overlay.cpp \
    plugin.cpp \
    gui/overlay/formoverlay.cpp \
    classes/userdata.cpp \
    classes/userdatalist.cpp

HEADERS += ts3_overlay.h\
    ts3_overlay_global.h \
    plugin.h \
    includes/clientlib_publicdefinitions.h \
    includes/plugin_definitions.h \
    includes/public_definitions.h \
    includes/public_errors.h \
    includes/public_errors_rare.h \
    includes/public_rare_definitions.h \
    includes/ts3_functions.h \
    gui/overlay/formoverlay.h \
    classes/userdata.h \
    classes/userdatalist.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    gui/overlay/formoverlay.ui
