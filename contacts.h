#ifndef CONTACTS_H
#define CONTACTS_H

#include <string>

class AddressBooks;  // Forward declaration

class Contacts {
public:
    std::string getName() const;
    void setName(const std::string& name);

    int getGender() const;
    void setGender(int gender);

    int getAge() const;
    void setAge(int age);

    std::string getPhone() const;
    void setPhone(const std::string& phone);

    std::string getAdd() const;
    void setAdd(const std::string& add);

private:
    std::string cName;
    int cGender;
    int cAge;
    std::string cPhone;
    std::string cAdd;
};

class AddressBooks {
public:
    AddressBooks();
    void addContact();
    void showContacts() const;
    void deleteContact();
    void getContact() const;
    void modifyContact();
    void clearContacts();
    void sortContacts(int choice);
    void backupContacts(const std::string& filename) const;
    void restoreContacts(const std::string& filename);
    void advancedSearch(const std::string& name, int age, int gender, const std::string& phone, const std::string& address) const;
    
    static const int Max = 100;

private:
    Contacts contactsArray[Max];
    int aCount;

    int isExist(const std::string& name) const;
    static bool compareByName(const Contacts& c1, const Contacts& c2);
    static bool compareByAge(const Contacts& c1, const Contacts& c2);
    static bool compareByGender(const Contacts& c1, const Contacts& c2);
};

void showMenu();

#endif  // CONTACTS_H
