#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::string;
using std::endl;

string convertApiProcessArchitecture(DWORD oem) {
    switch (oem) {
        case PROCESSOR_ARCHITECTURE_AMD64:
            return "x64 (AMD or Intel)";
        case PROCESSOR_ARCHITECTURE_ARM:
            return "ARM";
        case PROCESSOR_ARCHITECTURE_IA64:
            return "Intel Itanium";
        case PROCESSOR_ARCHITECTURE_INTEL:
            return "x86";
        default:
            return "unknown architecture";
    }
}

void logSystemInfo() {
    LPSYSTEM_INFO sysInfo;
    sysInfo = new SYSTEM_INFO();
    GetNativeSystemInfo(sysInfo);

    cout << "Process architecture: " << convertApiProcessArchitecture(sysInfo->wProcessorArchitecture) << endl;
    cout << "Number of processors: " << sysInfo->dwNumberOfProcessors << endl;
    cout << "Page size: " << sysInfo->dwPageSize << endl;
    cout << "Minimum application address: " << sysInfo->lpMinimumApplicationAddress << endl;
    cout << "Maximum application address: " << sysInfo->lpMaximumApplicationAddress << endl;
    cout << "Processor revision: " << sysInfo->wProcessorRevision << endl;
    cout << "Active processor mask: " << sysInfo->dwActiveProcessorMask << endl;
    cout << "Allocation granularity: " << sysInfo->dwAllocationGranularity << endl;
    cout << "Processor level: " << sysInfo->wProcessorLevel << endl;

    delete sysInfo;
}

