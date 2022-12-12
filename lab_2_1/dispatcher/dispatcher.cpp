#include <iostream>

#include "../log-system-info/log-system-info.h"
#include "../log-memory-status/log-memory-status.h"
#include "../log-memory-state-dialog/log-memory-state-dialog.h"
#include "../reserve-memory-dialog/reserve-memory-dialog.h"
#include "../record-to-memory-dialog/record-to-memory-dialog.h"

#include "../continue-on-key-enter/continue-on-key-enter.h"
#include "../reserve-memory-and-commit-dialog/reserve-memory-and-commit-dialog.h"
#include "../change-access-protection-dialog/change-access-protection-dialog.h"
#include "../free-or-bring-back-memory-dialog/free-or-bring-back-memory-dialog.h"

using std::cout;
using std::endl;

bool dispatcher(int choice) {
    switch (choice) {
        case 0:
            return false;
        case 1:
            logSystemInfo();
            break;
        case 2:
            logMemoryStatus();
            break;
        case 3:
            logMemoryStateDialog();
            break;
        case 4:
            reserveMemoryDialog();
            break;
        case 5:
            reserveMemoryAndCommitDialog();
            break;
        case 6:
            recordToMemoryDialog();
            break;
        case 7:
            changeAccessProtectionDialog();
            break;
        case 8:
            freeOrBringBackMemoryDialog();
            break;
        default:
            cout << "Bad input! Try again" << endl;
            break;
    }

    continueOnKeyEnter();

    return true;
}