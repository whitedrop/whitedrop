#include "../include/Utils.h"

namespace Scribe {
	namespace Utils {


		void Alert(const FunctionCallbackInfo<Value>& args)
		{


			if (args.Length())
			{
				String::Utf8Value message(args[0]->ToString());
				if (message.length())
				{
					MessageBoxA(0, *message, "Whitedrop", MB_OK);
				}
			}

		}

		void inject(Handle<ObjectTemplate> global, Isolate* isolate)
		{

			global->Set(String::NewFromUtf8(isolate, "ShowMessage"), FunctionTemplate::New(isolate, Alert));

		}
	}

}