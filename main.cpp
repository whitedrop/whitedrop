#include <windows.h>
#include "engine/lib/Whitedrop.h"
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
	if(Whitedrop::init())
		Whitedrop::run();
    return 0;
}