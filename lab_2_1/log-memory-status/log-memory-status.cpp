#include <iostream>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;

void logMemoryStatus() {
    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(memoryStatus);

    GlobalMemoryStatusEx(&memoryStatus);

    cout << endl <<"Memory status:" << endl << endl;
    cout << "Size of the data structure in bytes: " << memoryStatus.dwLength << "\n";
    cout << "Memory load: " << memoryStatus.dwMemoryLoad << "\n";
    cout << "The amount of actual physical memory in bytes: " << memoryStatus.ullTotalPhys << "\n";
    cout << "The amount of physical memory currently available, in bytes: " << memoryStatus.ullAvailPhys << "\n";
    cout << "The current committed memory limit in bytes: " << memoryStatus.ullTotalPageFile << "\n";
    cout << "The maximum amount of memory the current process can commit, in bytes: " << memoryStatus.ullAvailPageFile << "\n";
    cout << "The size of the user-mode portion of the virtual address space of the calling process, in bytes: " << memoryStatus.ullTotalVirtual << "\n";
}