# Alternative project file for Qt Creator and qmake

QT += core widgets
CONFIG += c++20

TARGET = Calculator
TEMPLATE = app

SOURCES += main.cpp \
        Calculator.cpp

HEADERS += Calculator.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
