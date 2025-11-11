# 🧾 InsuraPro Solutions – C++ CRM System

> Developed during **AI Engineering Master – Software Engineering Module**  
> A simple, interactive, and persistent **Customer Relationship Management (CRM)** system built with C++ and Object-Oriented Programming principles.

---

## 📌 Project Overview

**InsuraPro Solutions** was designed to help insurance companies manage customer information and their related interactions more efficiently.  
Many businesses rely on fragmented systems that reduce productivity and client satisfaction.  
This project provides a **console-based CRM application** that allows users to add, view, modify, delete, and search customers, as well as track their appointments and contracts.

All data is stored in memory using **C++ Standard Template Library (STL)** containers and persisted to CSV files, so information is kept across sessions.

---

## 🧱 Technologies and Concepts

- ✅ **C++17**
- ✅ **Object-Oriented Programming (OOP)**
- ✅ **Classes and Encapsulation**
- ✅ **File I/O with CSV**
- ✅ **Command-Line Interface (CLI)**
- ✅ **Data validation and error handling**
- ✅ **STL containers (`std::vector`)**

---

## 🚀 Features

- 🔹 **Add Customer** – Insert new customers with validated email and phone number.  
- 🔹 **List Customers** – Display all registered customers in a formatted table.  
- 🔹 **Search by Name/Surname** – Case-insensitive search through all customers.  
- 🔹 **Modify Customer** – Update name, surname, email, or phone (optional input).  
- 🔹 **Delete Customer** – Remove a customer and all linked interactions.  
- 🔹 **Add Interaction** – Add appointments or contracts associated with a customer.  
- 🔹 **List Interactions** – Show all interactions for a specific customer.  
- 🔹 **Data Persistence** – Automatically saves and loads data from `customers.csv` and `interactions.csv`.  

---

## 📂 Project Structure

InsuraPro/
├── main.cpp
├── Customer.h
├── Customer.cpp
├── Interaction.h
├── Interaction.cpp
├── CRM.h
├── CRM.cpp
├── customers.csv
├── interactions.csv
└── README.md


### Classes:
- **Customer** – represents an individual client and their contact info.  
- **Interaction** – represents customer-related events such as meetings or contracts.  
- **CRM** – core class handling all customers, interactions, and file persistence.  

---

## 🛠 How to Build and Run
### Compile:
```bash
g++ -std=c++17 main.cpp Customer.cpp Interaction.cpp CRM.cpp -o crm
./crm
```
## 🧮 Data Validation

- **Email:** must contain `@` and `.`  
- **Date:** must follow the format `DD/MM/YYYY`  
- **Phone:** must contain digits only  
- **Unique Email:** duplicate emails are not allowed  

---

## 📝 Notes

- Customer IDs are **auto-incremented** and **never reused**, ensuring data consistency.  
- The interface is fully text-based for simplicity and portability.  
- No external dependencies — the program uses only the C++ standard library.  

---

## 📎 License & Credits

This project was developed as part of the **AI Engineering Master**.  
No external libraries were used.  
All code and documentation authored by *[Your Name]*.  

GitHub: [ai-portfolio – silentfortin](https://github.com/silentfortin/ai-portfolio/tree/main/02-crm-insurance-cpp)
