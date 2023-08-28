QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#DEFINES += QT_NO_DEBUG_OUTPUT
INCLUDEPATH += include

SOURCES += \
    src/main.cpp \
    src/FirstWidget.cpp \
    src/LineEdit.cpp \
    src/Dialog.cpp \
    src/UserInfo.cpp

HEADERS += \
    include/FirstWidget.h \
    include/LineEdit.h \
    include/Dialog.h \
    include/UserInfo.h

FORMS += \
    FirstWidget.ui

RESOURCES += \
    resource.qrc

TRANSLATIONS += \
    resource/i18n/zh_CN.ts

RC_ICONS += resource/icon/shoko.ico

# 设置输出文件路径
release: DESTDIR = ./release
debug:   DESTDIR = ./debug

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

