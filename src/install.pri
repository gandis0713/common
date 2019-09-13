
CORE_INSTALL_PATH = ../output/corelib
CORE_INSTALL_INC_PATH = $${CORE_INSTALL_PATH}/include

## pri
    pri.path = $${CORE_INSTALL_PATH}
    pri.files = libcore.pri
    INSTALLS += pri

## include
    include_src.path = $${CORE_INSTALL_INC_PATH}
    include_src.files = *.h
    INSTALLS += include_src

    include_tools.path = $${CORE_INSTALL_INC_PATH}/tools
    include_tools.files = tools/*.h
    INSTALLS += include_tools

## lib
    library.path = $${CORE_INSTALL_PATH}
    library.files = $${DESTDIR}
    INSTALLS += library
