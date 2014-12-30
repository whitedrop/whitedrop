#include <windows.h>
// #include "parser/include/parser.h"
// #include "engine/include/Whitedrop.h"
#include <string>
#include <include/v8.h>
#include <include/libplatform/libplatform.h>
using namespace v8;
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
	// Parser::input("../media/maps/basic-map.json");
	// Parser::World world = Parser::load();
	
	// if(Whitedrop::init())
	// {
	// 	for(int i=0; i < world.entities.size(); i++){
 // 		  	std::string material = world.entities[i].material;
 // 		  	std::string mesh = world.entities[i].mesh;
 // 		  	std::string id = world.entities[i].id;
 // 		  	Whitedrop::Vector3 pos = Whitedrop::Vector3(world.entities[i].position.x, world.entities[i].position.y, world.entities[i].position.y);
 // 		  	Whitedrop::Vector3 dim = Whitedrop::Vector3(world.entities[i].dimensions.x, world.entities[i].dimensions.y, world.entities[i].dimensions.z);
	// 		Whitedrop::spawnEntity(mesh, id, pos, dim, material);
	// 	}		
		
	// 	Whitedrop::run();

	// }


  // Initialize V8.
  V8::InitializeICU();
  Platform* platform = platform::CreateDefaultPlatform();
  V8::InitializePlatform(platform);
  V8::Initialize();

  // Create a new Isolate and make it the current one.
  Isolate* isolate = Isolate::New();
  {
    Isolate::Scope isolate_scope(isolate);

    // Create a stack-allocated handle scope.
    HandleScope handle_scope(isolate);

    // Create a new context.
    Local<Context> context = Context::New(isolate);

    // Enter the context for compiling and running the hello world script.
    Context::Scope context_scope(context);

    // Create a string containing the JavaScript source code.
    Local<String> source = String::NewFromUtf8(isolate, "'Hello' + ', World!'");

    // Compile the source code.
    Local<Script> script = Script::Compile(source);

    // Run the script to get the result.
    Local<Value> result = script->Run();

    // Convert the result to an UTF8 string and print it.
    String::Utf8Value utf8(result);
    printf("%s\n", *utf8);
  }
  
  // Dispose the isolate and tear down V8.
  isolate->Dispose();
  V8::Dispose();
  V8::ShutdownPlatform();
  delete platform;

    return 0;
}