#include "mmseg.h"

using namespace node;
using namespace v8;

Persistent<FunctionTemplate> mmseg::constructor_template;

void mmseg::Initialize (Handle<Object> target)
{

	HandleScope scope;

	Local<FunctionTemplate> t = FunctionTemplate::New(New);
	t->InstanceTemplate()->SetInternalFieldCount(1);
	NODE_SET_PROTOTYPE_METHOD(t, "segmentSync", SegmentSync);
	NODE_SET_PROTOTYPE_METHOD(t, "complexSegmentSync", ComplexSegmentSync);
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
	Handle<String> str = args[0]->ToString();
	char path[str->Utf8Length()+1];
	str->WriteUtf8((char*) &path);
	init( path );
	return Undefined();
	//return args.This();
}	

Handle<Value> mmseg::SegmentSync (const Arguments& args)
{
	HandleScope scope;
	if (args.Length() == 0 || !args[0]->IsString()) {
		return Undefined();
	}
	Handle<String> str = args[0]->ToString();
	char words[str->Utf8Length()+1];
	str->WriteUtf8((char*) &words);
	Local<Array> ar = segmentSync(words);
	return ar;
}	

Handle<Value> mmseg::ComplexSegmentSync (const Arguments& args)
{
	HandleScope scope;
	if (args.Length() == 0 || !args[0]->IsString()) {
		return Undefined();
	}
	Handle<String> str = args[0]->ToString();
	char words[str->Utf8Length()+1];
	str->WriteUtf8((char*) &words);
	Local<Array> ar = complexSegmentSync(words);
	return ar;
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
	if (g_mgr.init(path) != 0) {
		perror(path);
		return 1;
	}
	g_bInited = true;
	return 0;
}

Local<Array> mmseg::segmentSync(char *f_words)
{
	Local<Array> ar = Array::New();
	if( !g_bInited ) {
		return ar;
	}
	int i = 0;
	css::Segmenter* seg = g_mgr.getSegmenter();
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

Local<Array> mmseg::complexSegmentSync(char *f_words)
{
	Local<Array> ar = Array::New();
	if( !g_bInited ) {
		return ar;
	}
	int i = 0;
	css::Segmenter* seg = g_mgr.getSegmenter();
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
		//check thesaurus
		{
			const char* thesaurus_ptr = seg->thesaurus(tok, symlen);
			while(thesaurus_ptr && *thesaurus_ptr) {
				len = strlen(thesaurus_ptr);
				ar->Set(i, String::New(thesaurus_ptr, len));
				i++;
				thesaurus_ptr += len + 1; //move next
			}
		}
	}
	//u2 len = 0, symlen = 0;
	//u2 kwlen = 0, kwsymlen = 0;
	////check ist token
	//char txtHead[3] = {239,187,191};
	//char* tok = (char*)seg->peekToken(len, symlen);
	//seg->popToken(len);
	//if(seg->isSentenceEnd()){
	//	do {
	//		char* kwtok = (char*)seg->peekToken(kwlen , kwsymlen,1);
	//		if(kwsymlen){
	//			//kw
	//			ar->Set(i, String::New(kwtok, kwsymlen));
	//			i++;
	//		}
	//	}while(kwsymlen);
	//}

	//if(len == 3 && memcmp(tok,txtHead,sizeof(char)*3) == 0){
	//	//check is 0xFEFF
	//	//do nothing
	//}else{
	//	ar->Set(i, String::New(tok, symlen));
	//	i++;
	//}
	//while(1)
	//{ 
	//	len = 0;
	//	char* tok = (char*)seg->peekToken(len,symlen);
	//	if(!tok || !*tok || !len){
	//		break;
	//	}
	//	seg->popToken(len);
	//	if(seg->isSentenceEnd()){
	//		do {
	//			char* kwtok = (char*)seg->peekToken(kwlen , kwsymlen,1);
	//			if(kwsymlen){
	//				ar->Set(i, String::New(kwtok, kwsymlen));
	//				i++;
	//			}
	//		}while(kwsymlen);
	//	}

	//	if(*tok == '\r')
	//		continue;
	//	if(*tok == '\n'){
	//		continue;
	//	}
	//	ar->Set(i, String::New(tok, symlen));
	//	i++;

	//}
	return ar;
}

void mmseg::destroy()
{
	if( g_bInited ){
		g_bInited = false;
	}
}

extern "C" void init (Handle<Object> target)
{
	HandleScope scope;
	mmseg::Initialize(target);
}

