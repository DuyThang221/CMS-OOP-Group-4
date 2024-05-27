#include "contacts.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <limits> 
#include <cstdlib>

using namespace std;

// Contacts class methods
std::string Contacts::getName() const { return cName; }
void Contacts::setName(const std::string& name) { cName = name; }

int Contacts::getGender() const { return cGender; }
void Contacts::setGender(int gender) { cGender = gender; }

int Contacts::getAge() const { return cAge; }
void Contacts::setAge(int age) { cAge = age; }

std::string Contacts::getPhone() const { return cPhone; }
void Contacts::setPhone(const std::string& phone) { cPhone = phone; }

std::string Contacts::getAdd() const { return cAdd; }
void Contacts::setAdd(const std::string& add) { cAdd = add; }

// AddressBooks class methods
AddressBooks::AddressBooks() : aCount(0) {}

void AddressBooks::addContact() {
    if (aCount == Max) {
        cout << "Address book is full." << endl;
        return;
    } else {
        cin.ignore(); // To ignore the newline character left by the previous input
        string name;
        cout << "Enter name: ";
        getline(cin, name);
        contactsArray[aCount].setName(name);

        int gender;
        cout << "Enter gender (1 for Male, 2 for Female): ";
        while (true) {
            cin >> gender;
            if (cin.fail() || (gender != 1 && gender != 2)) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Please enter 1 for Male or 2 for Female." << endl;
            } else {
                contactsArray[aCount].setGender(gender);
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from input buffer
                break;
            }
        }

        int age;
        cout << "Enter age: ";
        while (true) {
            cin >> age;
            if (cin.fail() || age <= 0) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Please enter a valid age (positive number)." << endl;
            } else {
                contactsArray[aCount].setAge(age);
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from input buffer
                break;
            }
        }

        cin.ignore(); // To ignore the newline character left by the previous input
        string phone;
        cout << "Enter phone number: ";
        while (true) {
            getline(cin, phone);
            bool valid = true;
            for (char c : phone) {
                if (!isdigit(c)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                contactsArray[aCount].setPhone(phone);
                break;
            }
            cout << "Invalid input. Please enter a valid phone number (digits only)." << endl;
        }

        string add;
        cout << "Enter address: ";
        getline(cin, add);
        contactsArray[aCount].setAdd(add);

        aCount++;
        cout << "Contact added successfully!" << endl;
        system("pause");
        system("cls");
    }
}

void AddressBooks::showContacts() const {
    if (aCount == 0) {
        cout << "No contacts found!" << endl;
    } else {
        for (int i = 0; i < aCount; i++) {
            cout << "Name: " << contactsArray[i].getName()
                 << ", Gender: " << (contactsArray[i].getGender() != 2 ? "Male" : "Female")
                 << ", Age: " << contactsArray[i].getAge()
                 << ", Phone: " << contactsArray[i].getPhone()
                 << ", Address: " << contactsArray[i].getAdd() << endl;
        }
    }
    system("pause");
    system("cls");
}

int AddressBooks::isExist(const std::string& name) const {
    for (int i = 0; i < aCount; i++) {
        if (contactsArray[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

void AddressBooks::deleteContact() {
    cin.ignore(); // To ignore the newline character left by the previous input
    string name;
    cout << "Enter the name of the contact you want to delete: ";
    getline(cin, name);

    int index = isExist(name);

    if (index > -1) {
        for (int i = index; i < aCount - 1; i++) {
            contactsArray[i] = contactsArray[i + 1];
        }
        aCount--;
        cout << "Contact deleted successfully!" << endl;
    } else {
        cout << "Contact not found!" << endl;
    }
    system("pause");
    system("cls");
}

void AddressBooks::getContact() const {
    cin.ignore(); // To ignore the newline character left by the previous input
    string name;
    cout << "Enter the name of the contact you want to search for: ";
    getline(cin, name);

    int index = isExist(name);
    if (index > -1) {
        cout << "Name: " << contactsArray[index].getName() << endl;
        cout << "Gender: " << (contactsArray[index].getGender() != 2 ? "Male" : "Female") << endl;
        cout << "Age: " << contactsArray[index].getAge() << endl;
        cout << "Phone: " << contactsArray[index].getPhone() << endl;
        cout << "Address: " << contactsArray[index].getAdd() << endl;
    } else {
        cout << "Contact not found!" << endl;
    }
    system("pause");
    system("cls");
}

void AddressBooks::modifyContact() {
    cin.ignore(); // To ignore the newline character left by the previous input
    string name;
    cout << "Enter the name of the contact you want to modify: ";
    getline(cin, name);

    int index = isExist(name);
    if (index > -1) {
        cout << "Enter the new name: ";
        string newName;
        getline(cin, newName);
        contactsArray[index].setName(newName);

        int gender;
        cout << "Enter the new gender (1 for Male, 2 for Female): ";
        while (true) {
            cin >> gender;
            if (gender == 1 || gender == 2) {
                contactsArray[index].setGender(gender);
                break;
            }
            cout << "Invalid input. Please enter again." << endl;
        }

        cout << "Enter the new age: ";
        int age;
        cin >> age;
        contactsArray[index].setAge(age);

        cin.ignore(); // To ignore the newline character left by the previous input
        cout << "Enter the new phone number: ";
        string phone;
        getline(cin, phone);
        contactsArray[index].setPhone(phone);

        cout << "Enter the new address: ";
        string add;
        getline(cin, add);
        contactsArray[index].setAdd(add);
        cout << "Contact modified successfully!" << endl;
    } else {
        cout << "Contact not found!" << endl;
    }
    system("pause");
    system("cls");
}

void AddressBooks::clearContacts() {
    string choice;
    cout << "Are you sure you want to clear all contacts? (Y for yes / N for no): ";
    cin >> choice;

    if (choice == "Y" || choice == "y") {
        aCount = 0;
        cout << "Contacts cleared successfully!" << endl;
    } else {
        cout << "Operation cancelled!" << endl;
    }
    system("pause");
    system("cls");
}

bool AddressBooks::compareByName(const Contacts& c1, const Contacts& c2) {
    return c1.getName() < c2.getName();
}

bool AddressBooks::compareByAge(const Contacts& c1, const Contacts& c2) {
    return c1.getAge() < c2.getAge();
}

bool AddressBooks::compareByGender(const Contacts& c1, const Contacts& c2) {
    return c1.getGender() < c2.getGender();
}

void AddressBooks::sortContacts(int choice) {
    switch (choice) {
    case 1:
        sort(contactsArray, contactsArray + aCount, compareByName);
        cout << "Contacts sorted by name." << endl;
        showContacts();
        break;
    case 2:
        sort(contactsArray, contactsArray + aCount, compareByAge);
        cout << "Contacts sorted by age." << endl;
        showContacts();
        break;
    case 3:
        sort(contactsArray, contactsArray + aCount, compareByGender);
        cout << "Contacts sorted by gender." << endl;
        showContacts();
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
    system("pause");
    system("cls");
}

void AddressBooks::backupContacts(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        cout << "Failed to open file for backup." << endl;
        return;
    }

    outFile << aCount << endl;
    for (int i = 0; i < aCount; i++) {
        outFile << contactsArray[i].getName() << endl;
        outFile << contactsArray[i].getGender() << endl;
        outFile << contactsArray[i].getAge() << endl;
        outFile << contactsArray[i].getPhone() << endl;
        outFile << contactsArray[i].getAdd() << endl;
    }
    outFile.close();
    cout << "Contacts backed up successfully!" << endl;
    system("pause");
    system("cls");
}

void AddressBooks::restoreContacts(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        cout << "Failed to open file for restore." << endl;
        return;
    }

    inFile >> aCount;
    inFile.ignore(); // Ignore the newline character after the count
    for (int i = 0; i < aCount; i++) {
        std::string name, phone, address;
        int gender, age;

        getline(inFile, name);
        inFile >> gender;
        inFile >> age;
        inFile.ignore(); // Ignore the newline character after age
        getline(inFile, phone);
        getline(inFile, address);

        contactsArray[i].setName(name);
        contactsArray[i].setGender(gender);
        contactsArray[i].setAge(age);
        contactsArray[i].setPhone(phone);
        contactsArray[i].setAdd(address);
    }
    inFile.close();
    cout << "Contacts restored successfully!" << endl;
    system("pause");
    system("cls");
}
void AddressBooks::advancedSearch(const std::string& name, int age, int gender, const std::string& phone, const std::string& address) const {
    bool found = false;
    for (int i = 0; i < aCount; i++) {
        bool match = true;
        if (!name.empty() && contactsArray[i].getName() != name) match = false;
        if (age != -1 && contactsArray[i].getAge() != age) match = false;
        if (gender != -1 && contactsArray[i].getGender() != gender) match = false;
        if (!phone.empty() && contactsArray[i].getPhone() != phone) match = false;
        if (!address.empty() && contactsArray[i].getAdd() != address) match = false;
        
        if (match) {
            found = true;
            cout << "Name: " << contactsArray[i].getName() << endl;
            cout << "Gender: " << (contactsArray[i].getGender() != 2 ? "Male" : "Female") << endl;
            cout << "Age: " << contactsArray[i].getAge() << endl;
            cout << "Phone: " << contactsArray[i].getPhone() << endl;
            cout << "Address: " << contactsArray[i].getAdd() << endl;
            cout << "--------------------------" << endl;
        }
    }
    if (!found) {
        cout << "No contacts matched the search criteria." << endl;
    }
    system("pause");
    system("cls");
}

void showMenu() {
    cout << "*********************************" << endl;
    cout << "***** Contact Management  *******" << endl;
    cout << "***********  System  ************" << endl;
    cout << "*********************************" << endl;
    cout << "*****    1. Add Contact     *****" << endl;
    cout << "*****    2. Show Contacts   *****" << endl;
    cout << "*****    3. Delete Contact  *****" << endl;
    cout << "*****    4. Search Contact  *****" << endl;
    cout << "*****    5. Modify Contact  *****" << endl;
    cout << "*****    6. Clear Contacts  *****" << endl;
    cout << "*****    7. Sort Contacts   *****" << endl;
    cout << "*****    8. Backup Contacts *****" << endl;
    cout << "*****    9. Restore Contacts*****" << endl;
    cout << "*****    0. Exit            *****" << endl;
    cout << "*********************************" << endl;
    cout << "******** Enter your choice ******" << endl;
    cout << "*********************************" << endl;
}
