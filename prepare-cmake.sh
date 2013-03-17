#!/bin/bash
set -eux

TOOLCHAIN_PREFIX=${TOOLCHAIN_PREFIX:-/opt/arm-2011.03-test}

CHECKOUT_DIR=/tmp/stm32-cmake-build

mkdir -p $CHECKOUT_DIR
cd $CHECKOUT_DIR

test -d $CHECKOUT_DIR/stm32-cmake || git clone git://github.com/ObKo/stm32-cmake.git

for i in cmsis stdperiph; do
    cd $CHECKOUT_DIR/stm32-cmake/$i
    rm -fr CMakeFiles CMakeCache.txt target
    mkdir target && cd target

    cmake -DSTM32_CHIP_TYPE=CL \
        -DCMAKE_TOOLCHAIN_FILE=../../gcc_stm32.cmake \
        -DCMAKE_BUILD_TYPE=Release \
        -DTOOLCHAIN_PREFIX=$TOOLCHAIN_PREFIX \
        -DCMAKE_INSTALL_PREFIX=$TOOLCHAIN_PREFIX/arm-none-eabi \
        ..

    make && make install
done

