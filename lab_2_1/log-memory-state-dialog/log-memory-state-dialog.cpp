#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;


string convertApiMemoryState(DWORD State) {
    switch (State) {
        case MEM_COMMIT:
            return "MEM_COMMIT";
        case MEM_FREE:
            return "MEM_FREE";
        case MEM_RESERVE:
            return "MEM_RESERVE";
        default:
            return "unknown";
    }
}

string convertApiMemoryType(DWORD Type) {
    switch (Type) {
        case MEM_IMAGE:
            return "MEM_IMAGE";
        case MEM_MAPPED:
            return "MEM_MAPPED";
        case MEM_PRIVATE:
            return "MEM_PRIVATE";
        default:
            return "unknown";
    }
}

void logMemoryStateDialog() {
    void* Memory;
    MEMORYSTATUS globalMemoryStatus;
    MEMORY_BASIC_INFORMATION selectedMemoryInfo;

    cout << endl << "Enter address: ";
    cin >> Memory;

    GlobalMemoryStatus(&globalMemoryStatus);
    VirtualQuery(Memory, &selectedMemoryInfo, sizeof(globalMemoryStatus));

    cout << "Pages information in the virtual address space: " << endl << endl;
    cout << "Pointer to the base address of the region of pages: " << selectedMemoryInfo.BaseAddress << endl;
    cout << "Pointer to the base address of a range of pages allocated by the VirtualAlloc function: "
         << selectedMemoryInfo.AllocationBase << endl;
    cout << "Memory protection option when the region was initially allocated: " << selectedMemoryInfo.AllocationProtect << endl;
    cout << "Size of the region beginning at the base address in which all pages have identical attributes, in bytes: "
         << selectedMemoryInfo.RegionSize << endl;
    cout << "State of the pages in the region: " << convertApiMemoryState(selectedMemoryInfo.State) << endl;
    cout << "Access protection of the pages in the region: " << selectedMemoryInfo.Protect << endl;
    cout << "The type of pages in the region: " << convertApiMemoryType(selectedMemoryInfo.Type);
}