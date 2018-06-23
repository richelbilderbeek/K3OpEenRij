CONFIG += c++14
QMAKE_CXXFLAGS += -Wall -Wextra -Werror -std=c++14

# Fix error: unrecognized option '--push-state--no-as-needed'
QMAKE_LFLAGS += -fuse-ld=gold

CONFIG += debug_and_release

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

CONFIG(release, debug|release) {
  message(Release mode)
  DEFINES += NDEBUG
}

include(../RibiClasses/CppAbout/CppAbout.pri)
include(../RibiClasses/CppFileIo/CppFileIo.pri)
include(../RibiClasses/CppHelp/CppHelp.pri)
include(../RibiClasses/CppMenuDialog/CppMenuDialog.pri)
include(../RibiClasses/CppQtAboutDialog/CppQtAboutDialog.pri)
include(../RibiClasses/CppQtHideAndShowDialog/CppQtHideAndShowDialog.pri)

#Specific, console
include(../DotMatrix/DotMatrix.pri)
include(../ConnectThree/CppConnectThree.pri)
include(../ConnectThree/CppConnectThreeWidget.pri)
include(../RibiClasses/CppTribool/CppTribool.pri)

#Specific, desktop
include(../ConnectThree/QtConnectThreeWidget.pri)
include(../ConnectThree/ConnectThreeDesktop.pri)

include(K3OpEenRijDesktop.pri)

SOURCES += qtmain.cpp

# C++14
CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14

# High warning levels
# Qt does not go well with -Weffc++
QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror

# Debug and release mode
CONFIG += debug_and_release

# In release mode, define NDEBUG
CONFIG(release, debug|release) {

  DEFINES += NDEBUG

  # gprof
  QMAKE_CXXFLAGS += -pg
  QMAKE_LFLAGS += -pg

  # GSL
  DEFINES += GSL_UNENFORCED_ON_CONTRACT_VIOLATION
}

# In debug mode, turn on gcov and UBSAN
CONFIG(debug, debug|release) {

  # gcov
  QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
  LIBS += -lgcov

  # UBSAN
  QMAKE_CXXFLAGS += -fsanitize=undefined
  QMAKE_LFLAGS += -fsanitize=undefined
  LIBS += -lubsan

  # gprof
  QMAKE_CXXFLAGS += -pg
  QMAKE_LFLAGS += -pg

  # GSL
  #DEFINES += GSL_THROW_ON_CONTRACT_VIOLATION
  DEFINES += GSL_UNENFORCED_ON_CONTRACT_VIOLATION
}

# Qt
QT += core gui widgets

# Prevent Qt for failing with this error:
# qrc_[*].cpp:400:44: error: ‘qInitResources_[*]__init_variable__’ defined but not used
# [*]: the resource filename
QMAKE_CXXFLAGS += -Wno-unused-variable

# Fixes
#/usr/include/boost/math/constants/constants.hpp:277: error: unable to find numeric literal operator 'operator""Q'
#   BOOST_DEFINE_MATH_CONSTANT(half, 5.000000000000000000000000000000000000e-01, "5.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e-01")
#   ^
QMAKE_CXXFLAGS += -fext-numeric-literals

message(Host name: $$QMAKE_HOST.name)
contains(QMAKE_HOST.name,pc-157-103) {
  message("Host is university computer in the canteen")
  QMAKE_CXX = g++-5
  QMAKE_LINK = g++-5
  QMAKE_CC = gcc-5
}
