
G_INSTALL_PATH = ../output/gandis
G_INSTALL_INC_PATH = $${G_INSTALL_PATH}/include

## pri
    pri.path = $${G_INSTALL_PATH}
    pri.files = libcore.pri
    INSTALLS += pri

## include
    include_core.path = $${G_INSTALL_INC_PATH}
    include_core.files = *.h
    INSTALLS += include_core

## lib
    library.path = $${G_INSTALL_PATH}
    library.files = $${DESTDIR}
    INSTALLS += library
