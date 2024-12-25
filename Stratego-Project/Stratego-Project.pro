TEMPLATE = subdirs

SUBDIRS += \
    controller \
    gui \
    main \
    model \
    test \
    view_console

gui.depends = controller

OTHER_FILES += config.pri


