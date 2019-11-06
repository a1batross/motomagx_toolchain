#!/bin/bash

export MOTOMAGXPATH=/opt/toolchains/motomagx
export TOOLPREFIX=$MOTOMAGXPATH/arm-eabi2
export QTDIR=$TOOLPREFIX/lib/qt-2.3.8
export EZXDIR=$TOOLPREFIX/lib/ezx-z6
export PATH=$QTDIR/bin:$TOOLPREFIX/bin:$PATH
export LFLAGS_EXTRA=" -Wl,-rpath-link,$TOOLPREFIX/arm-linux-gnueabi/lib "

export ARCH=iwmmxt