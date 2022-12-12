#include <iostream>
#include <windows.h>
#include <fileapi.h>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::string;

map<unsigned long, string> protectionFlags = {
        {PAGE_EXECUTE, "PAGE_EXECUTE"},
        {PAGE_EXECUTE_READ, "PAGE_EXECUTE_READ"},
        {PAGE_EXECUTE_READWRITE, "PAGE_EXECUTE_READWRITE"},
        {PAGE_EXECUTE_WRITECOPY, "PAGE_EXECUTE_WRITECOPY"},
        {PAGE_NOACCESS, "PAGE_NOACCESS"},
        {PAGE_READONLY, "PAGE_READONLY"},
        {PAGE_READWRITE, "PAGE_READWRITE"},
        {PAGE_WRITECOPY, "PAGE_WRITECOPY"},
};

void logProtectionFlags() {
    for (auto &flag: protectionFlags) {
        cout << flag.first << " - " << flag.second << endl;
    }
}

void changeAccessProtectionDialog() {

    MEMORY_BASIC_INFORMATION memoryInfo;
    PVOID Memory = nullptr;
    DWORD newProtection, oldProtection;

    cout << "Enter region memory address to change protection: ";
    cin >> Memory;

    VirtualQuery(Memory, &memoryInfo, sizeof(memoryInfo));

    if (GetLastError() != 0) {
        cout << "Bad memory address. Error: " << GetLastError() << endl;
        SetLastError(0);

        return;
    }

    cout << "Memory address: " << memoryInfo.BaseAddress << endl;
    cout << "Available protection flags: " << endl;
    logProtectionFlags();
    cout << "Choice new protection flag: " << endl;
    cin >> newProtection;

    bool isProtectionChanged = bool(
            VirtualProtect(
                    memoryInfo.BaseAddress,
                    memoryInfo.RegionSize,
                    newProtection,
                    &oldProtection
            )
    );

    if (isProtectionChanged) {
        cout << "Protection changed." << endl;
        cout << "Old protection: " << protectionFlags[oldProtection] << endl;
        cout << "New protection: " << protectionFlags[newProtection] << endl;
    } else {
        cout << "Failed" << endl;
        cout << "Error: " << GetLastError() << endl;
        SetLastError(0);
    }
}

