#include "../include/Interface.h"

namespace Scribe
{
	V8Interface::V8Interface()
	{

	}
	V8Interface::~V8Interface()
	{
		// Dispose the isolate and tear down V8.
		//isolate->Dispose();
		//V8::Dispose();
		//V8::ShutdownPlatform();
		//delete platform;
	}
	std::string readFile(std::string mapFile)
	{

		// std::string line;
		//std::ifstream map (mapFile);
		//if (map.is_open())
		//{
		// while ( getline (map, line) )
		//{
		//contents += line + '\n';
		//}
		//map.close();
		//}
		return "";
	}
	void V8Interface::initialize()
	{
		char* argv[] = { "iojs", "C:/OgreSDK/Projects/whitedrop/dist/media/scripts/hello.js", nullptr };
		int argc = 2;

		int exec_argc;
		const char** exec_argv;
		node::Init(&argc, const_cast<const char**>(argv), &exec_argc, &exec_argv);
		// Initialize V8.
		V8::InitializeICU();
		// Platform* platform = platform::CreateDefaultPlatform();
		V8::InitializePlatform(new node::Platform(4));
		V8::Initialize();

		// Create a new Isolate and make it the current one.
		mIsolate = Isolate::New();
		{
			Isolate::Scope isolate_scope(mIsolate);

			// Create a stack-allocated handle scope.
			HandleScope handle_scope(mIsolate);

			// Create a new context

			Handle<ObjectTemplate> globalTemplate = ObjectTemplate::New();

			Utils::inject(globalTemplate, mIsolate);
			Event::inject(globalTemplate, mIsolate);

			Local<Context> context = Context::New(mIsolate, NULL, globalTemplate);


			node::Environment* env = node::CreateEnvironment(
				mIsolate,
				uv_default_loop(),
				context,
				argc,
				argv,
				exec_argc,
				exec_argv);



			// Enter the context for compiling and running the hello world script.
			Context::Scope context_scope(context);

			// TODO: debug
			// Load env
			node::LoadEnvironment(env);

		}


	}
}