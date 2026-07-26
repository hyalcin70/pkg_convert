QT += core gui widgets
CONFIG += c++17 console
TARGET = pkg_convert_gui
TEMPLATE = app
SOURCES += pkg_convert_gui.cpp \
           lang_de.cpp \
           lang_en.cpp \
           lang_fr.cpp \
           lang_es.cpp \
           lang_tr.cpp \
           lang_pt.cpp
# keine extra Ressourcen noetig
