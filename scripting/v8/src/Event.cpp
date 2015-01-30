#include "../include/Event.h"
#include <iostream>
#include "../include/Interface.h"
namespace Scribe {
	namespace Event {
		typedef Persistent<Function, CopyablePersistentTraits<Function>> callback;
		typedef std::vector<callback> callbacks;

		std::map<std::string, callbacks> events;

		void addWorldEvent(const FunctionCallbackInfo<Value>& args)
		{

			if (args.Length())
			{
				String::Utf8Value event(args[0]->ToString());
				if (event.length())
				{  
					Isolate* isolate = V8Interface::getCurrent()->getIsolate();
					
					Locker locker(isolate);
					HandleScope scope(isolate);

					callback cb;
					cb.Reset(isolate, Local<Function>::Cast(args[1]));
					
					if(!events.count(*event))
					{
						events[*event] = callbacks({ cb });
					} 
					else 
					{
						events.find(*event)->second.push_back(cb);
					}
				}
			}

		}
		void trigger(std::string event)
		{

			Isolate* isolate = V8Interface::getCurrent()->getIsolate();
			
			Locker locker(isolate);
			HandleScope scope(isolate);
			
			if(events.count(event))
			{
				for(callback cb : events.find(event)->second)
				{
					Local<Function> local = Local<Function>::New(isolate, cb);
					local->Call(isolate->GetCurrentContext()->Global(), 0, {});
				}
			}
		}

		void V8WorldEvent::onUpdate(int timeSinceLastFrame)
		{
			trigger("update");
		}
		void V8WorldEvent::onExit()
		{
			trigger("exit");
		}
		void V8WorldEvent::onStart()
		{
			std::cout << "onstart" << std::endl;
			trigger("start");
		}

		void inject(Handle<ObjectTemplate> global, Isolate* isolate)
		{
			std::cout << "injecy" << std::endl;

			Whitedrop::worldEvents.push_back(new V8WorldEvent());
			global->Set(String::NewFromUtf8(isolate, "WorldOn"), FunctionTemplate::New(isolate, addWorldEvent));

		}
	}

}
		