include(../RibiLibraries/ConsoleApplication.pri)

include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/GeneralConsole.pri)

#Specific, console
include(../RibiClasses/CppConnectThree/CppConnectThree.pri)
include(../RibiClasses/CppConnectThreeWidget/CppConnectThreeWidget.pri)
include(../RibiClasses/CppDotMatrix/CppDotMatrix.pri)
include(../RibiClasses/CppTribool/CppTribool.pri)
include(../ConnectThree/GameConnectThreeConsole.pri)

include(K3OpEenRijConsole.pri)

SOURCES += main.cpp
