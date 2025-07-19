📇 ContactEase Solutions– Python Contact Manager

> Developed during **Week 1** of the [AI Engineering Master](https://github.com/silentfortin/ai-portfolio)  
> A simple, interactive, and persistent contact manager built with Python and Object-Oriented Programming principles.

---

📌 Project Overview

ContactEase aims to simplify how users manage their phone contacts. Many users struggle with organizing and accessing personal contact information efficiently. This project provides a **command-line interface (CLI)** for adding, modifying, deleting, and searching for contacts, all in one place.

Data is persistently stored in a **JSON file**, allowing the application to retain contact information across sessions.

---

🧱 Technologies and Concepts

- ✅ **Python 3**
- ✅ **Object-Oriented Programming (OOP)**
- ✅ **File I/O with JSON**
- ✅ **Command-Line Interface (CLI)**
- ✅ **ANSI escape codes for colored terminal output**
- ✅ **Data validation and user feedback**

---

🚀 Features

- 🔹 **Add Contact**: Create a new contact with validated name, surname, and phone number.
- 🔹 **Edit Contact**: Modify name, surname, or phone (with format validation).
- 🔹 **Remove Contact**: Delete an existing contact by name and surname.
- 🔹 **Search Contact**: Search contacts using name + surname.
- 🔹 **View All Contacts**: Display all stored contacts with formatted output.
- 🔹 **Data Persistence**: Automatically saves and loads contacts to/from `contacts_book.json`.

---

📂 Project Structure

All logic is implemented in a single `.ipynb` (Jupyter/Colab) file, structured into:

- `Contact` class: represents an individual contact.
- `ContactsBook` class: manages a collection of contacts.
- Helper functions: prompt, validation, and operation wrappers.
- CLI interface: a `main_menu()` loop for user interaction.

---

🛠 How to Use (in Colab or Locally)

1. Run all cells in order.
2. Interact with the main menu in the terminal or Colab cell.
3. Contacts are automatically saved and loaded from `contacts_book.json`.

---

📝 Notes

- Input validation ensures users cannot add empty fields or invalid phone numbers.
- JSON data includes unique `id` fields to prevent accidental overwrites.
- Uses Python’s `match-case` for clean conditional logic (Python 3.10+).

---

📎 License & Credits

This project is part of an individual portfolio developed for the **AI Engineering Master**.  
No external libraries are required.

GitHub: [ai-portfolio – silentfortin](https://github.com/silentfortin/ai-portfolio/)
