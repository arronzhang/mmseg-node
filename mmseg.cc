#include "mmseg.h"

using namespace node;
using namespace v8;

Persistent<FunctionTemplate> mmseg::constructor_template;

void mmseg::Initialize (Handle<Object> target)
{

	HandleScope scope;

	Local<FunctionTemplate> t = FunctionTemplate::New(New);
	t->InstanceTemplate()->SetInternalFieldCount(1);
	NODE_SET_PROTOTYPE_METHOD(t, "segment", Segment);
	NODE_SET_PROTOTYPE_METHOD(t, "close", Close);
	target->Set(String::NewSymbol("mmseg"), t->GetFunction());
}

Handle<Value> mmseg::New (const Arguments& args)
{
	HandleScope scope;
	if (args.Length() == 0 || !args[0]->IsString()) {
		return ThrowException(Exception::Error(
					String::New("Need data path")));
	}
	Handle<String> str = arg[0]->ToString();
	char path[str.Length()+1];
	str->WriteAscii((char*) &path);
	init( path );
	return Undefined();
	//return args.This();
}	

Handle<Value> mmseg::Segment (const Arguments& args)
{
	HandleScope scope;
	if (args.Length() == 0 || !args[0]->IsString()) {
		return Undefined();
	}
	Handle<String> str = arg[0]->ToString();
	char words[str.Length()+1];
	str->WriteAscii((char*) &words);
	Local<Array> ar = segment(words);
	return String::New(loc);
}	

Handle<Value> mmseg::Close (const Arguments& args)
{
	HandleScope scope;
	destroy();
	return Undefined();
}	

css::SegmenterManager g_mgr;
bool g_bInited = false;

int mmseg::init(char *path)
{
	if( g_bInited ) return 1;
	if (g_mgr->init(path) != 0) {
		delete g_mgr;
		perror(path);
		return 1;
	}
	g_bInited = true;
	return 0;
}

Local<Array> mmseg::segment(char *f_words)
{
	Local<Array> ar = Array::New();
	( !g_bInited ) {
		return ar;
	}
	int i = 0;
	Segmenter* seg = g_mgr->getSegmenter();
	seg->setBuffer((u1*)f_words, (u4)strlen(f_words));
	while(1)
	{ 
		u2 len = 0, symlen = 0;
		char* tok = (char*)seg->peekToken(len,symlen);
		if(!tok || !*tok || !len){
			break;
		}
		//append new item
		ar->Set(i, String::New(tok, len));
		i++;
		seg->popToken(len);
	}
	return ar;
}

void mmseg::destroy()
{
	if( g_bInited ){
		delete g_mgr;
		g_bInited = false;
	}
}

extern "C" void init (Handle<Object> target)
{
	HandleScope scope;
	mmseg::Initialize(target);
}

