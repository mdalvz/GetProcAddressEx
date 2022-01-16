#pragma once
#include <Windows.h>

FARPROC __cdecl GetProcAddressEx(HANDLE _Process, HMODULE _Module, LPCSTR _Name);

FARPROC __cdecl GetProcAddressEx(HANDLE _Process, LPCSTR _Module, LPCSTR _Name);