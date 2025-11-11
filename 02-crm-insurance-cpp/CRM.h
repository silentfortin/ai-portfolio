#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Customer.h"
#include "Interaction.h"

class CRM {
private:
    // list of all customers
    std::vector<Customer> customers;     
    // list of all interactions  
    std::vector<Interaction> interactions; 
    // auto-increment for customers
    int nextCustomerId = 1;  
    // auto-increment for interaction  
    int nextInteractionId = 1;             
public:
    // Customer management
    void addCustomer(const std::string& name,
                     const std::string& surname,
                     const std::string& email,
                     const std::string& phone);

    void listCustomers() const;
    Customer* findCustomerById(int id);
    void searchCustomerByName(const std::string& query) const;

    // interaction management
    void addInteraction(int customerId,
                        const std::string& type,
                        const std::string& date,
                        const std::string& notes);
    // modify
    void modifyCustomer(int id);

    // del
    void deleteCustomer(int id);
    
    void listInteractionsForCustomer(int customerId) const;

    // File management
    void saveData() const;
    void loadData();
};