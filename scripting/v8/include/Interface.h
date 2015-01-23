
// #include <v8.h>
// #include <libplatform/libplatform.h
#include <string>
#include <node.h>
#include <iostream>
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include <windows.h>

#pragma comment(lib, "winmm.lib")
#endif

using namespace v8;

namespace Scribe
{
  class V8Interface {
  public:
    V8Interface();
    ~V8Interface();
    void initialize();
  };
}