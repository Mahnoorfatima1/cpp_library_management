# Library Management System

This C++ program implements a simple Library Management System. It allows for the management of students, staff, and books. Users can add new members (students and staff), display member information, issue books to students, return books, and add new books to the library. Staff members also have the ability to search for books by their number.

## Features

* **User Management:**
    * Add new students and staff members with their ID and name.
    * Display lists of students and staff, including borrowed book information.
    * Search for users by ID.
* **Book Management:**
    * Add new books with their number, name, and author.
    * Search for books by book number.
    * Track book availability (issued or not).
* **Book Borrowing/Returning:**
    * Issue books to students (students can only borrow one book at a time).
    * Return borrowed books.

## How to Compile and Run

1. **Save:** Save the code as a `.cpp` file (e.g., `library_management.cpp`).
2. **Compile:** Use a C++ compiler (like g++) to compile the code. Open a terminal or command prompt and navigate to the directory where you saved the file. Then, compile using the following command:
   ```bash
   g++ library_management.cpp -o library_management
3. **Run:** Execute the compiled program:
   ```bash
   ./library_management
