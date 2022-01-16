#pragma once
#include <Windows.h>

#ifdef __cplusplus

extern "C" FARPROC __stdcall GetProcAddressEx(HANDLE _Process, HMODULE _Module, LPCSTR _Name);

extern "C" FARPROC __stdcall GetProcAddressByNameEx(HANDLE _Process, LPCSTR _Module, LPCSTR _Name);

#else

FARPROC __stdcall GetProcAddressEx(HANDLE _Process, HMODULE _Module, LPCSTR _Name);

FARPROC __stdcall GetProcAddressByNameEx(HANDLE _Process, LPCSTR _Module, LPCSTR _Name);

#endif