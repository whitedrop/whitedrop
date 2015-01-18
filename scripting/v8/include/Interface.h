
#include <include/v8.h>
#include <include/libplatform/libplatform.h>
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