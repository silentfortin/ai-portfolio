#pragma once

#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    int id;
    string name, surname, email, phone;

public:
    Customer(int id_, string name_, string surname_, string email_, string phone_);
    int getId() const;
    string getName() const;
    string getSurname() const;
    string getEmail() const;
    string getPhone() const;
    void setName(const string& user_name);
    void setSurname(const string& user_surname);
    void setEmail(const string& user_email);
    void setPhone(const string& user_phone);
    void printUserData() const;
};
