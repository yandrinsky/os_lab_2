#include <iostream>
#include <windows.h>
#include <fileapi.h>


using std::cout;
using std::cin;
using std::endl;

void recordToMemoryDialog() {
    MEMORY_BASIC_INFORMATION memInfo;
    LPVOID memoryAddress = nullptr;

    cout << "Enter memory address: ";
    cin >> memoryAddress;

    cout << "memoryAddress " << memoryAddress << endl;

    VirtualQuery(memoryAddress, &memInfo, sizeof(memInfo));

    if (GetLastError() != 0) {
        cout << "Bad address: " << GetLastError() << endl;

        SetLastError(0);

        return;
    }

    if (memInfo.State != MEM_COMMIT) {
        cout << "Error: memory state is not MEM_COMMIT" << endl;

        return;
    }

    SIZE_T memorySize = memInfo.RegionSize - ((SIZE_T) memoryAddress - (SIZE_T) memInfo.BaseAddress);
    SIZE_T sizeToWrite;

    cout << "Memory size is " << memorySize << " bytes" << endl;
    cout << "Enter amount of bytes to write: " << endl;
    cin >> sizeToWrite;

    if (sizeToWrite > memorySize) {
        cout << "Bad amount of bytes to write" << endl;

        return;
    }

    unsigned userNumber;
    byte *data = (byte *) memoryAddress;

    cout << "Enter " << sizeToWrite << " numbers from 0 to 255: ";

    for (SIZE_T i = 0; i < sizeToWrite; ++i) {
        cin >> userNumber;

        if (userNumber > 255 || userNumber < 0) {
            cout << "Bad number! Try again" << endl;
            i--;
        } else {
            *(data++) = userNumber;
        }
    }

    cout << "Success. The following data was written: ";

    for (SIZE_T i = 0; i < sizeToWrite; ++i) {
        userNumber = *((byte *) memoryAddress + i);

        cout << userNumber << " ";
    }
}

