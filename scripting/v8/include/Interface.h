#ifndef V8_INTERFACE_H
#define V8_INTERFACE_H

#include <node_v8_platform.h>
#include <uv.h>
#include <string>
#include <node.h>
#include <iostream>
#include "../include/Utils.h"
#include "../include/Event.h"

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
    static V8Interface* getCurrent();
    Isolate* getIsolate() const;
    void initialize();
   protected:
   	static V8Interface* currentInterface;
   	Isolate* mIsolate;
  };

}
#endif