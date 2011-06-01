
mmseg
==========================

  A nodeJS driver for [libmmseg](http://www.coreseek.cn/opensource/mmseg/)

## Install libmmseg

###libmmseg on ubuntu

	apt-get install make gcc g++ automake libtool
	wget http://www.coreseek.cn/uploads/csft/3.2/mmseg-3.2.14.tar.gz
	tar zxvf mmseg-3.2.14.tar.gz 
	cd mmseg-3.2.14
	./bootstrap 
	./configure
	make && make install
	#Install libmmseg on ubuntu

###libmmseg on mac os

	sudo port install autoconf263 libtool-devel m4 autoconf automake libtool
	wget http://www.coreseek.cn/uploads/csft/3.2/mmseg-3.2.14.tar.gz
	tar zxvf mmseg-3.2.14.tar.gz 
	cd mmseg-3.2.14
	aclocal &&  glibtoolize --copy --force --ltdl && autoreconf -i -f && automake --a && ./configure  && make && sudo make install

###Other system

Please check [the official install document](http://www.coreseek.cn/products-install/)

## Install mmseg-node

	#Install mmseg-node with npm
	#Set the os env MMSEG_PATH if you configure libmmseg with --prefix
	#export MMSEG_PATH=/usr/local/mmseg3
	npm install mmseg

##Useage

	var mmseg = require("mmseg");
	var q = mmseg.open('/usr/local/etc/');
	console.log(q.segmentSync("我是中文分词"));



## License 

(The MIT License)

Copyright (c) 2011 Hidden &lt;zzdhidden@gmail.com&gt;

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
