#include <iostream>
#include "../dispatcher/dispatcher.h"

using std::cout;
using std::cin;
using std::endl;

bool menu() {
    int choiceUser;

    system("cls");

    cout << "Select an action:" << endl << endl;
    cout << "1 - System info" << endl;
    cout << "2 - Virtual memory status" << endl;
    cout << "3 - Memory state by address" << endl;
    cout << "4 - Reserve region" << endl;
    cout << "5 - Reserve region and give memory" << endl;
    cout << "6 - Record to memory" << endl;
    cout << "7 - Change access protection" << endl;
    cout << "8 - Return memory or free the memory region" << endl;
    cout << "0 - Exit" << endl << endl;

    cin >> choiceUser;

    if (!choiceUser) {
        return false;
    }

    if(dispatcher(choiceUser)) {
        menu();
    }

    return true;
}