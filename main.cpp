#include <windows.h>
#include "engine/lib/Whitedrop.h"
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
	if(Whitedrop::init())
	{
		Whitedrop::spawnEntity("cube.mesh", "cube01", Whitedrop::Vector3(10, 10, 10), Whitedrop::Vector3(10, 10, 10));
		Whitedrop::spawnEntity("cube.mesh", "cube02", Whitedrop::Vector3(20, 10, 10), Whitedrop::Vector3(10, 10, 10));
		Whitedrop::spawnEntity("cube.mesh", "cube03", Whitedrop::Vector3(10, 50, 10), Whitedrop::Vector3(10, 10, 10));

		Whitedrop::spawnEntity("ogrehead.mesh", "ogre01", Whitedrop::Vector3(50, 50, 50), Whitedrop::Vector3(10, 10, 10));
		Whitedrop::run();

	}
    return 0;
}