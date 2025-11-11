#include "Interaction.h"
#include <iostream>
using namespace std;

// constructor
Interaction::Interaction(int id_, int customerId_, string type_, string date_, string notes_) {
    id = id_;
    customerId = customerId_;
    type = type_;
    date = date_;
    notes = notes_;
}

// getters
int Interaction::getId() const { return id; }
int Interaction::getCustomerId() const { return customerId; }
string Interaction::getType() const { return type; }
string Interaction::getDate() const { return date; }
string Interaction::getNotes() const { return notes; }

// setters
void Interaction::setType(const string& t) { type = t; }
void Interaction::setDate(const string& d) { date = d; }
void Interaction::setNotes(const string& n) { notes = n; }

// print info
void Interaction::printInteraction() const {
    cout << "Interaction [" << id << "] for Customer [" << customerId << "] - "
         << type << " on " << date << " | " << notes << endl;
}
