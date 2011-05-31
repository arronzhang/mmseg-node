#!/bin/sh

apt-get install make gcc g++ automake libtool
wget http://www.coreseek.cn/uploads/csft/3.2/mmseg-3.2.14.tar.gz
tar zxvf mmseg-3.2.14.tar.gz 
cd mmseg-3.2.14
./bootstrap 
#./configure --prefix=/usr/local/mmseg3
./configure
make && make install

#/usr/local/include/mmseg/ /usr/local/lib

