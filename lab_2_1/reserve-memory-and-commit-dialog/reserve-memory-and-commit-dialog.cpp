#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::cin;
using std::endl;

void reserveMemoryAndCommitDialog() {
    LPVOID memoryAddress;
    int choice;

    cout << "Reserve a memory region and commit" << endl;
    cout << "Enter action: " << endl;
    cout << "1 - Auto memory alloc" << endl;
    cout << "2 - Manually memory alloc" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            memoryAddress = VirtualAlloc(NULL, 4096, MEM_COMMIT, PAGE_READWRITE);

            if (memoryAddress) {
                cout << "Success: alloc and commit by address " << memoryAddress << endl;
            } else {
                cout << "Error: " << GetLastError() << endl;
                SetLastError(0);
            }

            break;
        case 2:
            cout << "Enter memory address: " << endl;
            cin >> memoryAddress;

            memoryAddress = VirtualAlloc(memoryAddress, 4096, MEM_COMMIT, PAGE_READWRITE);

            if (memoryAddress) {
                cout << "Success: alloc and commit by address " << memoryAddress << endl;
            }  else {
                cout << "Error: " << GetLastError() << endl;
                SetLastError(0);
            }

            break;
        default:
            cout << "Bad input!" << endl;
            break;
    }
}

