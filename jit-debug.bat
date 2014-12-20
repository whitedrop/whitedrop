@echo off

echo.
echo This batch file is going to open the VS Pro Just-In-Time debugger at the beginning
echo It will just triger a breakpoint. So just select "Debug this program"
echo See http://stackoverflow.com/a/12936476/2533082 with Whitedrop_jit.exe as executable
echo.
cd build_win32/dist/bin
echo.
copy Whitedrop_d.exe Whitedrop_jit.exe
echo.
Whitedrop_jit.exe
echo.
cd ../../../