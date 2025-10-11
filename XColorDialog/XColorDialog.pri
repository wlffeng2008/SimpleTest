# Copyright (C) 2013-2017 Mattia Basaglia
#
#
# This software is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with Color Widgets.  If not, see <http://www.gnu.org/licenses/>.
QT += xml
CONFIG += c++11

INCLUDEPATH += $$PWD/

SOURCES += \
$$PWD/language.cpp \
    $$PWD/XColorDialog.cpp \
    $$PWD/SColorDialog.cpp \
    $$PWD/XColorPreview.cpp \
    $$PWD/XColorSquare.cpp \
    $$PWD/SColorSquare.cpp \
    $$PWD/colorconfig.cpp \
    $$PWD/XGradientSlider.cpp 

HEADERS += \
$$PWD/colorLabel.h \
$$PWD/language.h \
    $$PWD/XColorDialog.h \
    $$PWD/SColorDialog.h \
    $$PWD/XColorPreview.hpp \
    $$PWD/XColorSquare.h \
    $$PWD/SColorSquare.h \
    $$PWD/colorconfig.h \
    $$PWD/XGradientSlider.hpp 

