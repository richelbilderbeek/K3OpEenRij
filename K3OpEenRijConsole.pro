include(../RibiLibraries/ConsoleApplicationNoWeffcpp.pri)

include(../RibiLibraries/Boost.pri)
include(../RibiClasses/CppAbout/CppAbout.pri)
include(../RibiClasses/CppFileIo/CppFileIo.pri)
include(../RibiClasses/CppHelp/CppHelp.pri)
include(../RibiClasses/CppMenuDialog/CppMenuDialog.pri)

#Specific, console
include(../ConnectThree/CppConnectThree.pri)
include(../ConnectThree/CppConnectThreeWidget.pri)
include(../DotMatrix/DotMatrix.pri)
include(../RibiClasses/CppTribool/CppTribool.pri)
include(../ConnectThree/ConnectThreeConsole.pri)

include(K3OpEenRijConsole.pri)

SOURCES += main.cpp

# Prevent Qt for failing with this error:
# qrc_[*].cpp:400:44: error: ‘qInitResources_[*]__init_variable__’ defined but not used
# [*]: the resource filename
QMAKE_CXXFLAGS += -Wno-unused-variable
