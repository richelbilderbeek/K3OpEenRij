QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
QMAKE_CXXFLAGS += -Wall -Wextra -std=c++14

# Go ahead and use Qt.Core: it is about as platform-independent as
# the STL and Boost
QT += core

# Go ahead and use Qt.Gui: it is about as platform-independent as
# the STL and Boost. It is needed for QImage
QT += gui

CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

CONFIG += debug_and_release

CONFIG(debug, debug|release) {
  message(Debug mode)
}

CONFIG(release, debug|release) {
  message(Release mode)
  DEFINES += NDEBUG
}


include(../RibiLibraries/BoostAll.pri)
include(../RibiLibraries/Wt.pri)

#Specific, console
include(../RibiClasses/CppWtAboutDialog/CppWtAboutDialog.pri)
include(../RibiClasses/CppWtAutoConfig/CppWtAutoConfig.pri)
include(../RibiClasses/CppAbout/CppAbout.pri)
include(../RibiClasses/CppFileIo/CppFileIo.pri)
include(../RibiClasses/CppHelp/CppHelp.pri)
include(../RibiClasses/CppMenuDialog/CppMenuDialog.pri)
include(../DotMatrix/DotMatrix.pri)
include(../ConnectThree/ConnectThree.pri)
include(../ConnectThree/ConnectThreeWidget.pri)
include(../ConnectThree/WtConnectThreeWidget.pri)
include(../RibiClasses/CppTribool/CppTribool.pri)

#Specific, web
include(K3OpEenRijWebsite.pri)
include(../RibiClasses/CppWtConnectThreeWidget/CppWtConnectThreeWidget.pri)
include(../ConnectThree/ConnectThreeWebsite.pri)

SOURCES += wtmain.cpp

DEFINES += BOOST_SIGNALS_NO_DEPRECATION_WARNING

