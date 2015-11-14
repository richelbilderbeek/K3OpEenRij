include(../RibiLibraries/WebApplication.pri)

include(../RibiLibraries/BoostAll.pri)
include(../RibiLibraries/Wt.pri)
include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralWeb.pri)

#Specific, console
include(../RibiClasses/CppDotMatrix/CppDotMatrix.pri)
include(../RibiClasses/CppConnectThree/CppConnectThree.pri)
include(../RibiClasses/CppConnectThreeWidget/CppConnectThreeWidget.pri)
include(../RibiClasses/CppTribool/CppTribool.pri)

#Specific, web
include(K3OpEenRijWebsite.pri)
include(../RibiClasses/CppWtConnectThreeWidget/CppWtConnectThreeWidget.pri)
include(../ConnectThree/GameConnectThreeWebsite.pri)

SOURCES += wtmain.cpp

#/home/richel/ProjectRichelBilderbeek/Games/GameConnectThree/qtconnectthreeresources.
