#include <iostream>
#include <windows.h>
#include <fileapi.h>


using std::cout;
using std::cin;
using std::endl;

void reserveMemoryDialog() {
    cout << "Enter way of memory alloc:" << endl;
    LPVOID memoryAddress;
    LPVOID isAllocatedMemory;
    int choice;

    cout << "1 - Auto memory alloc" << endl;
    cout << "2 - Manually memory alloc" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            memoryAddress = VirtualAlloc(NULL, 4096, MEM_RESERVE, PAGE_READWRITE);

            if (memoryAddress) {
                cout << "Success. Virtual address is: " << memoryAddress << endl;
            } else {
                cout << "An error occurred: " << GetLastError() << endl;
            }

            break;
        case 2:
            cout << "Enter memory address " << endl;
            cin >> memoryAddress;

            isAllocatedMemory = VirtualAlloc(memoryAddress, 4096, MEM_RESERVE, PAGE_READWRITE);

            if (isAllocatedMemory) {
                cout << "Success" << endl;
            } else {
                cout << "An error occurred: " << GetLastError() << endl;
            }

            break;
        default:
            cout << "Bad input!" << endl;
    }

}




