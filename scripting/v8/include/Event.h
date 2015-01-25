#ifndef SCRIBE_V8_EVENT_H
#define SCRIBE_V8_EVENT_H

#include <env.h>
#include <../../../common/include/Event.h>
#include <v8.h>
#include <node.h>
#include <windows.h>
#include <vector>
#include <string>
#include <map>

using namespace v8;

namespace Scribe {
	namespace Event {
		class V8WorldEvent : public Whitedrop::WorldEvent {

		public:
			virtual void onUpdate(int timeSinceLastFrame);
			virtual void onExit();
			virtual void onStart();
		};
		void addWorldEvent(const FunctionCallbackInfo<Value>& args);
		void inject(Handle<ObjectTemplate> global, Isolate* isolate);

	}

}
#endif