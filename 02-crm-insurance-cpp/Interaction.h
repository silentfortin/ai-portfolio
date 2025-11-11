#pragma once // !!!remember to avoid error: redefinition of 'class Interaction'

#include <iostream>
#include <string>
using namespace std;

class Interaction {
private:
    int id;
    int customerId;
    string type, date, notes;

public:
    Interaction(int id_, int customerId_, string type_, string date_, string notes_);
    int getId() const;
    int getCustomerId() const;
    string getType() const;
    string getDate() const;
    string getNotes() const;
    void setType(const string& t);
    void setDate(const string& d);
    void setNotes(const string& n);
    void printInteraction() const;
};
