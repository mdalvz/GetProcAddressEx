#pragma once
#include <Windows.h>

FARPROC __stdcall GetProcAddressEx(HANDLE _Process, HMODULE _Module, LPCSTR _Name);

#ifdef __cplusplus

FARPROC __stdcall GetProcAddressEx(HANDLE _Process, LPCSTR _Module, LPCSTR _Name);

#endif