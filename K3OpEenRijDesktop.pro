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
include(../ConnectThree/ConnectThreeDesktop.pri)

include(K3OpEenRijDesktop.pri)

SOURCES += qtmain.cpp

win32:RC_ICONS += K3OpEenRijIcon.ico
#win32:RC_ICONS += :/images/K3OpEenRijIcon.ico
