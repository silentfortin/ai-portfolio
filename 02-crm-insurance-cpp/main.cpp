#include <iostream>
#include <limits>
#include "CRM.h"
using namespace std;

// clear input buffer to avoid issues with getline after numeric input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// basic email validation: must contain '@' and '.' after it
bool isValidEmail(const string& email) {
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos + 1);

    // must contain '@' and '.' in correct order
    if (atPos == string::npos || dotPos == string::npos)
        return false;

    // must not start or end with '@' or '.'
    if (atPos == 0 || dotPos == email.size() - 1)
        return false;

    // at least one character between '@' and '.'
    if (dotPos - atPos <= 1)
        return false;

    return true;
}

int main() {
    CRM crm;
    // load from CSV files at startup
    crm.loadData(); 
    int choice;

    // header display
    cout << "------------------------------\n";
    cout << "     InsuraPro CRM System     \n";
    cout << "------------------------------\n";

    // main loop for the console menu
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Customer\n";
        cout << "2. List Customers\n";
        cout << "3. Search Customer by Name\n";
        cout << "4. Add Interaction\n";
        cout << "5. List Interactions for Customer\n";
        cout << "6. Modify Customer\n";
        cout << "7. Delete Customer\n";
        cout << "8. Exit\n";
        cout << "Select an option: ";

        cin >> choice;
        // avoid leftover characters in input stream
        clearInput(); 

        if (choice == 1) {
            // add new customer
            string name, surname, email, phone;
            cout << "Name: ";
            getline(cin, name);
            cout << "Surname: ";
            getline(cin, surname);
            cout << "Email: ";
            getline(cin, email);

            if (!isValidEmail(email)) {
                cout << "Invalid email format. Please try again.\n";
                continue;
            }

            // short number are not allowed
            cout << "Phone: ";
            getline(cin, phone);

            // basic phone validation: must be at least 6 digits and all numeric or '+' allowed
            bool valid = true;
            if (phone.size() < 6)
                valid = false;
            else {
                for (char c : phone) {
                    if (!isdigit(c) && c != '+' && c != ' ') {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) {
                cout << "Invalid phone number. Please enter at least 6 digits.\n";
                // back to menu
                continue; 
            }

            crm.addCustomer(name, surname, email, phone);

        } else if (choice == 2) {
            // display all customers
            crm.listCustomers();

        } else if (choice == 3) {
            // search customer by name or surname
            string query;
            cout << "Enter name or surname to search: ";
            getline(cin, query);
            crm.searchCustomerByName(query);

        } else if (choice == 4) {
            int customerId;
            cout << "Customer ID: ";
            cin >> customerId;
            clearInput();

            // check if the customer exists before asking for interaction details (avoid waste of time)
            Customer* existing = crm.findCustomerById(customerId);
            if (!existing) {
                cout << "Error: Customer ID not found.\n";
                // go back to menu
                continue; 
            }

            string type, date, notes;
            cout << "Interaction type (e.g. Appointment, Contract): ";
            getline(cin, type);
            // date
            cout << "Date (DD/MM/YYYY): ";
            getline(cin, date);

            // a basic date validation (format: DD/MM/YYYY)
            bool validDate = true;
            int slashCount = 0;

            for (char c : date) {
                if (c == '/') slashCount++;
                else if (!isdigit(c)) validDate = false;
            }

            if (slashCount != 2 || date.size() < 8)
                validDate = false;

            if (!validDate) {
                cout << "Invalid date format. Please use DD/MM/YYYY\n";
                continue; // back to menu
            }

            //notes
            cout << "Notes: ";
            getline(cin, notes);

            crm.addInteraction(customerId, type, date, notes);

        } else if (choice == 5) {
            // list interactions for a given customer
            int customerId;
            cout << "Enter Customer ID: ";
            cin >> customerId;
            clearInput();
            crm.listInteractionsForCustomer(customerId);

        } else if (choice == 6) {
            int id;
            cout << "Enter Customer ID to modify: ";
            cin >> id;
            clearInput();
            crm.modifyCustomer(id);

        } else if (choice == 7) {
            int id;
            cout << "Enter Customer ID to delete: ";
            cin >> id;
            clearInput();
            crm.deleteCustomer(id);

        } else if (choice == 8) {
            cout << "Exiting program...\n";
            break;

        } else {
            // invalid menu choice
            cout << "Invalid choice. Try again.\n";
        }
    }

    cout << "Program terminated\n";
    // save to CSV files before exit
    crm.saveData(); 
    return 0;
}