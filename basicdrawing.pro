QT += widgets
requires(qtConfig(combobox))

HEADERS       = renderarea.h \
                draw.h \
                ellipse.h \
                line.h \
                loginwidget.h \
                mainw.h \
                mainwindow.h \
                polygon.h \
                polyline.h \
                rectangle.h \
                shapes.h \
                text.h \
                vector.h \
                window.h
SOURCES       = main.cpp \
                draw.cpp \
                ellipse.cpp \
                line.cpp \
                loginwidget.cpp \
                mainw.cpp \
                mainwindow.cpp \
                polygon.cpp \
                polyline.cpp \
                rectangle.cpp \
                renderarea.cpp \
                shapes.cpp \
                text.cpp \
                vector.cpp \
                window.cpp
RESOURCES     = basicdrawing.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/painting/basicdrawing
INSTALLS += target

FORMS += \
    mainw.ui
