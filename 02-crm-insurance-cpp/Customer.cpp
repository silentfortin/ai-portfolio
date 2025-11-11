#include "Customer.h"
#include <iostream>
using namespace std;

// constructor
Customer::Customer(int id_, string name_, string surname_, string email_, string phone_) {
    id = id_;
    name = name_;
    surname = surname_;
    email = email_;
    phone = phone_;
}

// getters
int Customer::getId() const { return id; }
string Customer::getName() const { return name; }
string Customer::getSurname() const { return surname; }
string Customer::getEmail() const { return email; }
string Customer::getPhone() const { return phone; }

// setters
void Customer::setName(const string& user_name) { name = user_name; }
void Customer::setSurname(const string& user_surname) { surname = user_surname; }
void Customer::setEmail(const string& user_email) { email = user_email; }
void Customer::setPhone(const string& user_phone) { phone = user_phone; }

// print basic info
void Customer::printUserData() const {
    cout << "Customer [" << id << "]: " << name << " " << surname
         << " | Email: " << email << " | Phone: " << phone << endl;
}
