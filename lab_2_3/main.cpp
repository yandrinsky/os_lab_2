#include <iostream>

#include<windows.h>
#include<string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void continueOnKeyEnter() {
    char mainPage;

    cout << endl << "Enter any key to continue: ";
    cin >> mainPage;
}

int main() {
    string filePath;
    string fileName;
    HANDLE fileHandle;
    HANDLE HandleMap;
    char *str = new char[5000];
    LPVOID viewOfFile;

    cout << "Enter filepath: ";
    cin >> filePath;
    cout << "Enter filename: ";
    cin >> fileName;

    fileHandle = CreateFileA(
            filePath.c_str(),
            GENERIC_READ | GENERIC_WRITE,
            FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE,
            NULL,
            CREATE_ALWAYS,
            FILE_ATTRIBUTE_NORMAL,
            NULL
    );

    HandleMap = CreateFileMappingA(fileHandle, NULL, PAGE_READWRITE, 0, 1024, fileName.c_str());
    viewOfFile = MapViewOfFile(HandleMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

    if (viewOfFile) {
        cout << "Enter string without spaces: ";
        cin >> str;

        memcpy(viewOfFile, str, strlen(str) * sizeof(char));

        cout << "Success! Open reader program." << endl;
        continueOnKeyEnter();

        UnmapViewOfFile(viewOfFile);
    } else {
        cout << "Error:" << GetLastError() << endl;
    }

    return 0;
}
