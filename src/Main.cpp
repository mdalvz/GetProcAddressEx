#include <GetProcAddressEx.h>

#include <TlHelp32.h>

#undef PROCESSENTRY32
#undef Process32First
#undef Process32Next

#include <iostream>

static HANDLE FindProcess(char* _Name) {

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (snapshot == INVALID_HANDLE_VALUE)
        return nullptr;
    
    PROCESSENTRY32 entry = { 0 };

    entry.dwSize = sizeof(entry);

    for (BOOL status = Process32First(snapshot, &entry); status == TRUE; status = Process32Next(snapshot, &entry)) {

        if (!_strcmpi(_Name, entry.szExeFile)) {

            CloseHandle(snapshot);

            return OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);

        }

    }

    CloseHandle(snapshot);

    return nullptr;

}

int main(int argc, char** argv) {

    if (argc != 4)
        return -1;
    
    HANDLE process = FindProcess(argv[1]);

    if (!process)
        return -2;
    
    FARPROC address = GetProcAddressByNameEx(process, argv[2], argv[3]);

    if (!address) {

        std::cout << '\"' << argv[3] << "\" not found." << std::endl;

    }
    else {

        std::cout << reinterpret_cast<void*>(address) << std::endl;

    }

    CloseHandle(process);

    return 0;

}