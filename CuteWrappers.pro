#-------------------------------------------------
#
# Project created by QtCreator 2011-10-23T17:25:37
#
#-------------------------------------------------

QT       += core

TARGET = CuteWrappers
TEMPLATE = lib


SOURCES +=\
	CuteSettings.cpp

HEADERS  += \
	CuteSettings.h



target.path = /usr/lib
INSTALLS += target


header_files.files = $$HEADERS
header_files.path = /usr/include/CuteWrappers
INSTALLS += header_files
