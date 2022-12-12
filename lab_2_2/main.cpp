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
    HANDLE handleFileMap;
    LPVOID viewOfFile;

    cout << "Enter file path: ";
    cin >> filePath;

    handleFileMap = OpenFileMappingA(FILE_MAP_READ | FILE_MAP_WRITE, FALSE, filePath.c_str());
    viewOfFile = MapViewOfFile(handleFileMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

    if (viewOfFile) {
        cout << "File contents: " << (char *) viewOfFile << endl << endl;
        continueOnKeyEnter();

        UnmapViewOfFile(viewOfFile);
    } else {
       cout << "Error:" << GetLastError() << endl;
    }

    return 0;
}
