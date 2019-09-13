#-------------------------------------------------
#
# Project created by QtCreator 2019-08-30T21:46:15
#
#-------------------------------------------------

QT       -= gui

TARGET = corelib
TEMPLATE = lib

DEFINES += CORELIB_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#DESTDIR = build/lib
#OBJECTS_DIR = temp/obj
#MOC_DIR = temp/moc
#RCC_DIR = temp/rcc

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    tools/costring.cpp

HEADERS += \
    corelib.h \
    tools/codefine.h \
    tools/covector.h \
    tools/costring.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    libcore.pri

include(install.pri);


