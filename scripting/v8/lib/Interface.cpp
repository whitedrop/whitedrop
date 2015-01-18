#include "../include/Interface.h"

namespace Scribe
{
  V8Interface::V8Interface()
  {

  }
  V8Interface::~V8Interface()
  {
  // Dispose the isolate and tear down V8.
    isolate->Dispose();
    V8::Dispose();
    V8::ShutdownPlatform();
    delete platform;
  }
  std::string readFile(std::string mapFile)
  {

      std::string line;
      std::ifstream map (mapFile);
      if (map.is_open())
      {
        while ( getline (map, line) )
        {
          contents += line + '\n';
        }
        map.close();
      }
  }
  void V8Interface::initialize()
  {
  // Initialize V8.
    V8::InitializeICU();
    Platform* platform = platform::CreateDefaultPlatform();
    V8::InitializePlatform(platform);
    V8::Initialize();

  // Create a new Isolate and make it the current one.
   mIsolate = Isolate::New();
    {
      Isolate::Scope isolate_scope(isolate);

    // Create a stack-allocated handle scope.
      HandleScope handle_scope(isolate);

    // Create a new context.
      Local<Context> context = Context::New(isolate);

    // Enter the context for compiling and running the hello world script.
      Context::Scope context_scope(context);

    // Create a string containing the JavaScript source code.

      Local<String> source = String::NewFromUtf8(isolate, "../media/scripts/hello.js");


    // Compile the source code.
      Local<Script> script = Script::Compile(source);

    // Run the script to get the result.
      Local<Value> result = script->Run();

    // Convert the result to an UTF8 string and print it.
      String::Utf8Value utf8(result);
      printf("%s\n", *utf8);
    }

  }
}