#include <iostream>
#include <cstring>
using namespace std;
const int MAX_USERS = 100;
const int MAX_BOOKS = 100;
struct User {
    string id;
    string name;
    string borrowedBook;
};
struct Book {
    string bookNo;
    string name;
    string author;
    bool isIssued;
};
User students[MAX_USERS];
User staff[MAX_USERS];
Book books[MAX_BOOKS];
int numStudents = 0, numStaff = 0, numBooks = 0;
void addUser(User users[], int& numUsers, const string& userType) {
    if (numUsers >= MAX_USERS) {
        cout << "Maximum number of " << userType << "s reached.\n";
        return;
    }
    cout << "Enter the " << userType << " ID: ";
    cin >> users[numUsers].id;
    cout << "Enter the " << userType << "'s name: ";
    cin.ignore();
    getline(cin, users[numUsers].name);
    users[numUsers].borrowedBook = "";
    numUsers++;
    cout << userType << " record created.\n";
}
void displayUsers(const User users[], int numUsers, const string& userType) {
    cout << "\nList of " << userType << "s:\n";
    for (int i = 0; i < numUsers; i++) {
        cout << "\n" << userType << ": " << users[i].name << endl;
        if (!users[i].borrowedBook.empty()) {
            cout << "Borrowed Book: " << users[i].borrowedBook << endl;
        } else {
            cout << "No book borrowed.\n";
        }
    }
}
int searchUser(const User users[], int numUsers, const string& userID) {
    for (int i = 0; i < numUsers; i++) {
        if (users[i].id == userID) {
            return i;
        }
    }
    return -1;
}
void issueBook(User users[], int numStudents, Book books[], int& numBooks) {
    string userID, bookNo;
    
    cout << "Enter user's ID: ";
    cin >> userID;

    int userIndex = searchUser(students, numStudents, userID);
    if (userIndex == -1) {
        cout << "User not found.\n";
        return;
    }

    if (!students[userIndex].borrowedBook.empty()) {
        cout << "User already has a book.\n";
        return;
    }

    cout << "Enter book number to issue: ";
    cin >> bookNo;

    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookNo == bookNo) {
            if (books[i].isIssued) {
                cout << "Book is already issued.\n";
                return;
            }
            students[userIndex].borrowedBook = bookNo;
            books[i].isIssued = true;
            cout << "Book issued successfully.\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

void returnBook(User users[], int numStudents, Book books[], int& numBooks) {
    string userID;
    cout << "Enter user's ID: ";
    cin >> userID;

    int userIndex = searchUser(students, numStudents, userID);
    if (userIndex == -1) {
        cout << "User not found.\n";
        return;
    }

    if (students[userIndex].borrowedBook.empty()) {
        cout << "User has not borrowed any book.\n";
        return;
    }

    string bookNo = students[userIndex].borrowedBook;

    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookNo == bookNo) {
            books[i].isIssued = false;
            students[userIndex].borrowedBook = "";
            cout << "Book returned successfully.\n";
            return;
        }
    }

    cout << "Book not found in the library.\n";
}

void addBook(Book books[], int& numBooks) {
    if (numBooks >= MAX_BOOKS) {
        cout << "Maximum number of books reached.\n";
        return;
    }

    cout << "\nNEW BOOK ENTRY...\n";
    cout << "Enter the book number: ";
    cin >> books[numBooks].bookNo;
    cout << "Enter the book name: ";
    cin.ignore();
    getline(cin, books[numBooks].name);
    cout << "Enter the author's name: ";
    getline(cin, books[numBooks].author);
    books[numBooks].isIssued = false;

    numBooks++;
    cout << "\nBook record created.\n";
}

int searchBook(const Book books[], int numBooks, const string& bookNo) {
    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookNo == bookNo) {
            return i;
        }
    }
    return -1;
}

int main() {
    int choice, userChoice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Student\n";
        cout << "2. Staff\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Student Menu
                do {
                    cout << "\nStudent Menu\n";
                    cout << "1. Add Student\n";
                    cout << "2. Display Students\n";
                    cout << "3. Issue Book\n";
                    cout << "4. Return Book\n";
                    cout << "0. Back\n";
                    cout << "Enter your choice: ";
                    cin >> userChoice;

                    switch (userChoice) {
                        case 1:
                            addUser(students, numStudents, "Student");
                            break;
                        case 2:
                            displayUsers(students, numStudents, "Student");
                            break;
                        case 3:
                            issueBook(students, numStudents, books, numBooks);
                            break;
                        case 4:
                            returnBook(students, numStudents, books, numBooks);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid choice.\n";
                    }
                } while (userChoice != 0);
                break;

            case 2: // Staff Menu
                do {
                    cout << "\nStaff Menu\n";
                    cout << "1. Add Staff\n";
                    cout << "2. Display Staff\n";
                    cout << "3. Add Book\n";
                    cout << "4. Search Book\n";
                    cout << "0. Back\n";
                    cout << "Enter your choice: ";
                    cin >> userChoice;

                    switch (userChoice) {
                        case 1:
                            addUser(staff, numStaff, "Staff");
                            break;
                        case 2:
                            displayUsers(staff, numStaff, "Staff");
                            break;
                        case 3:
                            addBook(books, numBooks);
                            break;
                        case 4: {
                            string bookNo;
                            cout << "Enter book number to search: ";
                            cin >> bookNo;

                            int bookIndex = searchBook(books, numBooks, bookNo);
                            if (bookIndex == -1) {
                                cout << "Book not found.\n";
                            } else {
                                cout << "Book found:\n";
                                cout << "Book Number: " << books[bookIndex].bookNo << endl;
                                cout << "Book Name: " << books[bookIndex].name << endl;
                                cout << "Author: " << books[bookIndex].author << endl;
                            }
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Invalid choice.\n";
                    }
                } while (userChoice != 0);
                break;

            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
