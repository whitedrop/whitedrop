#ifndef V8_INTERFACE_H
#define V8_INTERFACE_H

#include <node_v8_platform.h>
#include <uv.h>
#include <string>
#include <node.h>
#include <iostream>
#include "../include/Utils.h"

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
   protected:
   	Isolate* mIsolate;
  };
}
#endif