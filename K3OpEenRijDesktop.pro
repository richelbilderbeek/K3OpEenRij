include(../RibiLibraries/DesktopApplicationNoWeffcpp.pri)
include(../RibiLibraries/Boost.pri)

include(../RibiClasses/CppAbout/CppAbout.pri)
include(../RibiClasses/CppFileIo/CppFileIo.pri)
include(../RibiClasses/CppHelp/CppHelp.pri)
include(../RibiClasses/CppMenuDialog/CppMenuDialog.pri)

include(../RibiLibraries/GeneralDesktop.pri)

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

win32:RC_ICONS += K3OpEenRijIcon.ico
#win32:RC_ICONS += :/images/K3OpEenRijIcon.ico

# Prevent Qt for failing with this error:
# qrc_[*].cpp:400:44: error: ‘qInitResources_[*]__init_variable__’ defined but not used
# [*]: the resource filename
QMAKE_CXXFLAGS += -Wno-unused-variable
