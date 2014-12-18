#include <windows.h>
 
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
    MessageBox ( NULL, "Hello World!", "Test", MB_OK );
    return 0;
}