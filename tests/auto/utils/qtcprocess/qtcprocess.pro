QTC_LIB_DEPENDS += utils
include(../../qttest.pri)

win32:DEFINES += _CRT_SECURE_NO_WARNINGS

TEST_RELATIVE_LIBEXEC_PATH = $$relative_path($$IDE_LIBEXEC_PATH, $$OUT_PWD)
win32:TEST_RELATIVE_LIBEXEC_PATH=../$$TEST_RELATIVE_LIBEXEC_PATH
DEFINES += 'TEST_RELATIVE_LIBEXEC_PATH="\\\"$$TEST_RELATIVE_LIBEXEC_PATH\\\""'

SOURCES +=  tst_qtcprocess.cpp