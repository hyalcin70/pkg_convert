QT += core gui widgets
CONFIG += c++17 console
TARGET = pkg_convert_gui
TEMPLATE = app
SOURCES += pkg_convert_gui.cpp \
           lang/lang_de.cpp \
           lang/lang_en.cpp \
           lang/lang_fr.cpp \
           lang/lang_es.cpp \
           lang/lang_tr.cpp \
           lang/lang_pt.cpp
# keine extra Ressourcen noetig
