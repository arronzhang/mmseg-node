#ifndef MMSEG_H
#define MMSEG_H

#include <node.h>

#include <v8.h>
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>

#include <algorithm>

#include <stdio.h>
#include <stdexcept>
#include "SegmenterManager.h"
#include "Segmenter.h"

using namespace node;
using namespace v8;

class mmseg: ObjectWrap
{
	public:
		static void Initialize(Handle<Object> target);
	protected:
		static Persistent<FunctionTemplate> constructor_template;
		static Handle<Value> New (const Arguments& args);
		static Handle<Value> SegmentSync (const Arguments& args);
		static Handle<Value> ComplexSegmentSync (const Arguments& args);
		static Handle<Value> Close (const Arguments& args);

		mmseg () : ObjectWrap() {
		};

		~mmseg (){};

	private:
		static int init(char *path);
		static Local<Array>  segmentSync(char *f_words);
		static Local<Array>  complexSegmentSync(char *f_words);
		static void destroy();
};

#endif
