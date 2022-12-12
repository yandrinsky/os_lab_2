#include <iostream>
#include <windows.h>
#include <fileapi.h>


using std::cout;
using std::cin;
using std::endl;

void freeOrBringBackMemoryDialog() {
    SIZE_T memorySize;
    int choice;
    bool isSuccess;
    PVOID memoryAddress;

    cout << "Enter action: " << endl;
    cout << "1 - Free a memory region" << endl;
    cout << "2 - Get back a part of memory" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter address: " << endl;
        cin >> memoryAddress;

        isSuccess = bool(VirtualFree(memoryAddress, 0, MEM_RELEASE));
    } else if (choice == 2) {
        cout << "Enter size to bring back:";
        cin >> memorySize;
        cout << "Enter address: " << endl;
        cin >> memoryAddress;

        isSuccess = bool(VirtualFree(memoryAddress, memorySize, MEM_DECOMMIT));
    }

    if (!isSuccess) {
        cout << "Error: " << GetLastError() << endl;
        SetLastError(0);

        return;
    }

    cout << "Ok" << endl;
}

