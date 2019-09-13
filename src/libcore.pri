CORE_LIB_PATH = $${PWD}/lib
CORE_INC_PATH = $${PWD}/include

INCLUDEPATH += $${CORE_INC_PATH}/ \
    $${CORE_INC_PATH}/tools \

LIBS += -L$${CORE_LIB_PATH} -lcorelib

