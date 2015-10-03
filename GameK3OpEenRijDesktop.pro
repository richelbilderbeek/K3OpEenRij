include(../RibiLibraries/DesktopApplication.pri)
include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralDesktop.pri)

#Specific, console
include(../RibiClasses/CppDotMatrix/CppDotMatrix.pri)
include(../RibiClasses/CppConnectThree/CppConnectThree.pri)
include(../RibiClasses/CppConnectThreeWidget/CppConnectThreeWidget.pri)
include(../RibiClasses/CppTribool/CppTribool.pri)

#Specific, desktop
include(../RibiClasses/CppQtConnectThreeWidget/CppQtConnectThreeWidget.pri)
include(../ConnectThree/GameConnectThreeDesktop.pri)

include(GameK3OpEenRijDesktop.pri)

SOURCES += qtmain.cpp
