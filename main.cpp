#include "contacts.h"
#include <iostream>
#include <cstdlib> // For system()

using namespace std;

int main()
{
    int select = 0;
    AddressBooks abs;
    string searchName, searchPhone, searchAddress;
    while (true)
    {
        showMenu();
        cin >> select;

        switch(select)
        {
        case 1:
            system("cls");
            abs.addContact();
            break;
        case 2:
            system("cls");
            abs.showContacts();
            break;
        case 3:
            system("cls");
            abs.deleteContact();
            break;
        case 4:
            system("cls");
            abs.getContact();
            break;
        case 5:
            system("cls");
            abs.modifyContact();
            break;
        case 6:
            system("cls");
            abs.clearContacts();
            break;
        case 7:
            system("cls");
            int sortChoice;
            cout << "Sort by:" << endl;
            cout << "1. Name" << endl;
            cout << "2. Age" << endl;
            cout << "3. Gender" << endl;
            cout << "Enter your choice: ";
            cin >> sortChoice;
            abs.sortContacts(sortChoice);
            break;
        case 8:
            abs.backupContacts("backup.txt");
            break;
        case 9:
            abs.restoreContacts("backup.txt");
            break;
        case 0:
            cout << "Welcome back! Goodbye!" << endl;
            system("pause");
            return 0;
        default:
            cout << "Choice Invalid! Choose again!" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}
