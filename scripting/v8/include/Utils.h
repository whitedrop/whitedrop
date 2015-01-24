#ifndef  SCRIBE_V8_UTILS_H
#define SCRIBE_V8_UTILS_H

#include <env.h>

#include <v8.h>
#include <node.h>
#include <windows.h>

using namespace v8;

namespace Scribe {
	namespace Utils {

		void Alert(const FunctionCallbackInfo<Value>& args);
		void inject(Handle<ObjectTemplate> global, Isolate* isolate);

	}

}
#endif