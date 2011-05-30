#include <v8.h>
#include "SegmenterManager.h"
#include "Segmenter.h"

using namespace v8;

extern "C" void
init (Handle<Object> target)
{
	HandleScope scope;
	target->Set(String::New("hello"), String::New("world"));
}
