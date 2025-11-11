#include "CRM.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

// add new customer
void CRM::addCustomer(const std::string& name,
                      const std::string& surname,
                      const std::string& email,
                      const std::string& phone) {

    // check if email already exists (or same name + email)
    for (const auto& c : customers) {
        if (c.getEmail() == email ||
           (c.getName() == name && c.getSurname() == surname && c.getEmail() == email)) {
            std::cout << "Duplicate error: a customer with this email already exists\n";
            return;
        }
    }

    Customer c(nextCustomerId++, name, surname, email, phone);
    customers.push_back(c);
    std::cout << "Customer added successfully\n";
}

// list all customers
void CRM::listCustomers() const {
    std::cout << "\n--- Customer List ---\n";
    if (customers.empty()) {
        std::cout << "No customers available\n";
        return;
    }
    for (const auto& c : customers)
        c.printUserData();
}

// find customer by ID
Customer* CRM::findCustomerById(int id) {
    for (auto& c : customers) {
        if (c.getId() == id)
            return &c;
    }
    return nullptr;
}

// handling case sensitive
std::string toLower(const std::string& s) {
    std::string res = s;
    std::transform(res.begin(), res.end(), res.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return res;
}

// search customer by name or surname
void CRM::searchCustomerByName(const std::string& query) const {
    std::cout << "\n--- Search results for \"" << query << "\" ---\n";
    bool found = false;

    std::string lowerQuery = toLower(query);
    for (const auto& c : customers) {
        std::string fullName = c.getName() + " " + c.getSurname();
        std::string lowerFullName = toLower(fullName);

        if (lowerFullName.find(lowerQuery) != std::string::npos) {
            c.printUserData();
            found = true;
        }
    }

    if (!found)
        std::cout << "No matching customers found\n";
}

// modify an existing customer by ID
void CRM::modifyCustomer(int id) {
    Customer* c = findCustomerById(id);
    if (!c) {
        std::cout << "Error: Customer ID not found\n";
        return;
    }

    std::string newName, newSurname, newEmail, newPhone;

    std::cout << "Enter new name (leave empty to keep current): ";
    std::getline(std::cin, newName);
    if (!newName.empty()) c->setName(newName);

    std::cout << "Enter new surname (leave empty to keep current): ";
    std::getline(std::cin, newSurname);
    if (!newSurname.empty()) c->setSurname(newSurname);

    std::cout << "Enter new email (leave empty to keep current): ";
    std::getline(std::cin, newEmail);
    if (!newEmail.empty()) c->setEmail(newEmail);

    std::cout << "Enter new phone (leave empty to keep current): ";
    std::getline(std::cin, newPhone);
    if (!newPhone.empty()) c->setPhone(newPhone);

    std::cout << "Customer updated successfully\n";
}

// delete a customer by ID (and related interactions)
void CRM::deleteCustomer(int id) {
    auto it = std::remove_if(customers.begin(), customers.end(),
                             [id](const Customer& c) { return c.getId() == id; });
    if (it == customers.end()) {
        std::cout << "Error: Customer ID not found\n";
        return;
    }

    customers.erase(it, customers.end());

    // remove all interactions related to that customer
    interactions.erase(std::remove_if(interactions.begin(), interactions.end(),
                                      [id](const Interaction& i) { return i.getCustomerId() == id; }),
                       interactions.end());

    std::cout << "Customer and related interactions deleted\n";
}

// add new interaction
void CRM::addInteraction(int customerId,
                         const std::string& type,
                         const std::string& date,
                         const std::string& notes) {
    Customer* customer = findCustomerById(customerId);
    if (!customer) {
        std::cout << "Error: Customer ID not found\n";
        return;
    }
    Interaction i(nextInteractionId++, customerId, type, date, notes);
    interactions.push_back(i);
    std::cout << "Interaction added successfully\n";
}

// list all interactions for one customer
void CRM::listInteractionsForCustomer(int customerId) const {
    std::cout << "\n--- Interactions for Customer [" << customerId << "] ---\n";
    bool found = false;
    for (const auto& i : interactions) {
        if (i.getCustomerId() == customerId) {
            i.printInteraction();
            found = true;
        }
    }
    if (!found)
        std::cout << "No interactions found for this customer\n";
} 

// save all customers and interactions to CSV files
void CRM::saveData() const {
    std::ofstream custFile("customers.csv");
    if (!custFile) {
        std::cout << "Writing Error:: could not open customers.csv\n";
        return;
    }

    for (const auto& c : customers) {
        custFile << c.getId() << ","
                 << c.getName() << ","
                 << c.getSurname() << ","
                 << c.getEmail() << ","
                 << c.getPhone() << "\n";
    }
    custFile.close();

    std::ofstream interFile("interactions.csv");
    if (!interFile) {
        std::cout << "Writing Error: could not open interactions.csv\n";
        return;
    }

    for (const auto& i : interactions) {
        interFile << i.getId() << ","
                  << i.getCustomerId() << ","
                  << i.getType() << ","
                  << i.getDate() << ","
                  << i.getNotes() << "\n";
    }
    interFile.close();

    std::cout << "Data saved successfully\n";
}

// load customers and interactions from CSV files
void CRM::loadData() {
    std::ifstream custFile("customers.csv");
    if (custFile) {
        std::string line;
        while (getline(custFile, line)) {
            std::stringstream ss(line);
            std::string idStr, name, surname, email, phone;

            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, surname, ',');
            getline(ss, email, ',');
            getline(ss, phone, ',');

            if (!idStr.empty()) {
                int id = stoi(idStr);
                customers.emplace_back(id, name, surname, email, phone);
                if (id >= nextCustomerId) nextCustomerId = id + 1;
            }
        }
        custFile.close();
    }

    std::ifstream interFile("interactions.csv");
    if (interFile) {
        std::string line;
        while (getline(interFile, line)) {
            std::stringstream ss(line);
            std::string idStr, custIdStr, type, date, notes;

            getline(ss, idStr, ',');
            getline(ss, custIdStr, ',');
            getline(ss, type, ',');
            getline(ss, date, ',');
            getline(ss, notes, ',');

            if (!idStr.empty()) {
                int id = stoi(idStr);
                int custId = stoi(custIdStr);
                interactions.emplace_back(id, custId, type, date, notes);
                if (id >= nextInteractionId) nextInteractionId = id + 1;
            }
        }
        interFile.close();
    }

    std::cout << "Data loaded successfully\n";
}
