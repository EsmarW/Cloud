QT += widgets
requires(qtConfig(combobox))

HEADERS       = renderarea.h \
                draw.h \
                line.h \
                loginwidget.h \
                mainw.h \
                mainwindow.h \
                rectangle.h \
                shapes.h \
                vector.h \
                window.h
SOURCES       = main.cpp \
                draw.cpp \
                line.cpp \
                loginwidget.cpp \
                mainw.cpp \
                mainwindow.cpp \
                rectangle.cpp \
                renderarea.cpp \
                shapes.cpp \
                vector.cpp \
                window.cpp
RESOURCES     = basicdrawing.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/painting/basicdrawing
INSTALLS += target

FORMS += \
    mainw.ui
