TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include(../config.pri)

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../controller/release/ -lcontroller
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../controller/debug/ -lcontroller
else:unix: LIBS += -L$$OUT_PWD/../controller/ -lcontroller

INCLUDEPATH += $$PWD/../controller
DEPENDPATH += $$PWD/../controller

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../controller/release/libcontroller.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../controller/debug/libcontroller.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../controller/release/controller.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../controller/debug/controller.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../controller/libcontroller.a

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
