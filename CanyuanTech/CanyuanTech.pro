QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(cyBackStageWidget.pri)      #后台控件
include(cyModifyToolWidget.pri)         #自定义控件
include(cyMainFaceWidget.pri)       #主界面

SOURCES += \
  #  cybackstagealarmvaluewidget.cpp \
 #   cybackstageareanoncrashwidget.cpp \
  #  cybackstagebananglearea.cpp \
 #   cybackstagebancirclearea.cpp \
#    cybackstagebansquarearea.cpp \
 #  cybackstagedatasetwidget.cpp \
 #   cybackstagefuncswitchwidget.cpp \
#    cybackstageinputidwidget.cpp \
#    cybackstageoverloadwidget.cpp \
#   cybackstagepages.cpp \
#    cybackstagesystemsettingswidget.cpp \
#    cybackstagetowerinfo.cpp \
#    cybackstagetowerinstallinfowidget.cpp \
#    cybackstagewidgets.cpp \
   # cybottomwidgetelement.cpp \
   # cyinputlineeditwidget.cpp \
    #cylineedit.cpp \
   # cylogin.cpp \
    #cypaintcircle.cpp \
    #cypushbutton.cpp \
  #  cysignalwidget.cpp \
    #cyswitchbutton.cpp \
  #  cyswitchbuttonwidget.cpp \
  #  cyusertowerwidget.cpp \
  #  cyvoicebackstagebtn.cpp \
    main.cpp \
    mainwidget.cpp \
 #   topwidgetelement.cpp

HEADERS += \
 #   cybackstagealarmvaluewidget.h \
  #  cybackstageareanoncrashwidget.h \
   # cybackstagebananglearea.h \
 #   cybackstagebancirclearea.h \
  #  cybackstagebansquarearea.h \
   # cybackstagedatasetwidget.h \
   # cybackstagefuncswitchwidget.h \
  #  cybackstageinputidwidget.h \
   # cybackstageoverloadwidget.h \
   # cybackstagepages.h \
    #cybackstagesystemsettingswidget.h \
   # cybackstagetowerinfo.h \
    #cybackstagetowerinstallinfowidget.h \
   # cybackstagewidgets.h \
  #  cybottomwidgetelement.h \
  #  cyinputlineeditwidget.h \
    #cylineedit.h \
  #  cylogin.h \
    #cypaintcircle.h \
    #cypushbutton.h \
   # cysignalwidget.h \
    #cyswitchbutton.h \
  #  cyswitchbuttonwidget.h \
   # cyusertowerwidget.h \
   # cyvoicebackstagebtn.h \
    global.h \
    mainwidget.h \
   # topwidgetelement.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    cyBackStageWidget.pri \
    cyMainFaceWidget.pri \
    cyModifyToolWidget.pri
