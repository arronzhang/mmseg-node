#!/bin/sh

apt-get install make gcc g++ automake libtool
wget http://www.coreseek.cn/uploads/csft/3.2/mmseg-3.2.14.tar.gz
tar zxvf mmseg-3.2.14.tar.gz 
cd mmseg-3.2.14
ls
./bootstrap 
./configure --prefix=/usr/local/mmseg3
make && make install

#echo '/usr/local/mmseg3/lib' > /etc/ld.so.conf.d/mmseg.conf
