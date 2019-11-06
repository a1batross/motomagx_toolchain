#!/bin/bash

export MOTOMAGXPATH=/opt/toolchains/motomagx
export TOOLPREFIX=$MOTOMAGXPATH/arm-eabi2
export QTDIR=$TOOLPREFIX/lib/qt-2.3.8
export EZXDIR=$TOOLPREFIX/lib/ezx-z6
export PATH=$QTDIR/bin:$TOOLPREFIX/bin:$PATH
export LFLAGS_EXTRA=" -Wl,-rpath-link,$TOOLPREFIX/arm-linux-gnueabi/lib "
export PKG_CONFIG_PATH="$TOOLPREFIX/lib/pkgconfig"

# export CFLAGS=" -march=armv6j -mtune=arm1136jf-s -mfpu=vfp -Os -O3"
# export CXXFLAGS=" -march=armv6j -mtune=arm1136jf-s -mfpu=vfp -Os -O3"
export CFLAGS=""
export CXXFLAGS=""
export CC="arm-linux-gnueabi-gcc -march=armv6j -mtune=arm1136jf-s -mfpu=vfp "
export CXX="arm-linux-gnueabi-g++ -march=armv6j -mtune=arm1136jf-s -mfpu=vfp "
export LD=arm-linux-gnueabi-ld
export AR=arm-linux-gnueabi-ar
export AS=arm-linux-gnueabi-as
export OC=arm-linux-gnueabi-objcopy
export RANLIB=arm-linux-gnueabi-ranlib
export STRIP=arm-linux-gnueabi-strip
