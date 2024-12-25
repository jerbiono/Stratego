QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

include(../config.pri)


SOURCES += \
        Controller.cpp \
    Observable.cpp



DISTFILES += \
    fichierJoueur1.txt \
    fichierJoueur1.txt

HEADERS += \
    Controller.h \
    Observable.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../model/release/ -lmodel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../model/debug/ -lmodel
else:unix: LIBS += -L$$OUT_PWD/../model/ -lmodel

INCLUDEPATH += $$PWD/../model
DEPENDPATH += $$PWD/../model

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../model/release/libmodel.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../model/debug/libmodel.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../model/release/model.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../model/debug/model.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../model/libmodel.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../view_console/release/ -lview_console
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../view_console/debug/ -lview_console
else:unix: LIBS += -L$$OUT_PWD/../view_console/ -lview_console

INCLUDEPATH += $$PWD/../view_console
DEPENDPATH += $$PWD/../view_console

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../view_console/release/libview_console.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../view_console/debug/libview_console.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../view_console/release/view_console.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../view_console/debug/view_console.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../view_console/libview_console.a

unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

