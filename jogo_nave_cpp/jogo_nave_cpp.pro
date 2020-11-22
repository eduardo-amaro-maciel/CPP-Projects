QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        uteis.cpp

TRANSLATIONS += \
    jogo_nave_cpp_pt_BR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    uteis.h

win32: LIBS += -L$$PWD/'../bibliotecas cpp/SDL2-2.0.12/x86_64-w64-mingw32_m/lib/' -lSDL2

INCLUDEPATH += $$PWD/'../bibliotecas cpp/SDL2-2.0.12/x86_64-w64-mingw32_m/include'
DEPENDPATH += $$PWD/'../bibliotecas cpp/SDL2-2.0.12/x86_64-w64-mingw32_m/include'
