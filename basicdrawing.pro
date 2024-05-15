QT += widgets
requires(qtConfig(combobox))

HEADERS       = \
                aboutuswidget.h \
                add.h \
                draw.h \
                ellipse.h \
                fileparser.h \
                line.h \
                loginwidget.h \
                mainw.h \
                move.h \
                polygon.h \
                polyline.h \
                rectangle.h \
                shapes.h \
                text.h \
                vector.h
SOURCES       = main.cpp \
                aboutuswidget.cpp \
                add.cpp \
                draw.cpp \
                ellipse.cpp \
                fileparser.cpp \
                line.cpp \
                loginwidget.cpp \
                mainw.cpp \
                move.cpp \
                polygon.cpp \
                polyline.cpp \
                rectangle.cpp \
                shapes.cpp \
                text.cpp \
                vector.cpp
RESOURCES     = basicdrawing.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/painting/basicdrawing
INSTALLS += target

FORMS += \
    aboutuswidget.ui \
    add.ui \
    mainw.ui \
    move.ui

DISTFILES += \
    ../logo.png \
    shapes.txt
