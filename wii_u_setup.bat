@echo off
set mingw64exe="C:\msys64\mingw64.exe"
if exist %mingw64exe% (
	%mingw64exe% bash -c "python3 wii_u_setup.py"
)
