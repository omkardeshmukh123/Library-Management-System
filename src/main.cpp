#include <iostream>
#include <limits>
#include "../include/Library.h"
#include "../include/Exceptions.h"

using namespace std;

// Function prototypes
void clearScreen();
void pauseScreen();
void displayMainMenu();
void displayStudentMenu(shared_ptr<Person> user);
void displayFacultyMenu(shared_ptr<Person> user);
void displayLibrarianMenu(shared_ptr<Person> user);
void registerNewUser(Library* lib);
void loginUser(Library* lib);
void addNewItem(Library* lib);
void searchItems(Library* lib);

int main() {
    Library* library = Library::getInstance();
    
    // Add sample data for demonstration
    try {
        // Sample users
        library->registerStudent("S001", "Alice Johnson", "alice@email.com", "pass123", 20,
                                "STU2024001", "Computer Science", 3);
        library->registerFaculty("F001", "Dr. Bob Smith", "bob@email.com", "pass456", 45,
                                "EMP001", "Computer Science", "Professor");
        library->registerLibrarian("L001", "Charlie Brown", "charlie@email.com", "pass789", 35,
                                  "LIB001", "Morning");
        
        // Sample items
        library->addBook("B001", "Introduction to Algorithms", "MIT Press", 2009,
                        "978-0262033848", "Thomas H. Cormen", "Computer Science", 1312);
        library->addBook("B002", "Clean Code", "Prentice Hall", 2008,
                        "978-0132350884", "Robert C. Martin", "Software Engineering", 464);
        library->addMagazine("M001", "National Geographic", "National Geographic Society",
                           2024, 156, "January", "Science");
        library->addJournal("J001", "Nature", "Springer Nature", 2024, 625,
                          "Multidisciplinary", "Dr. Magdalena Skipper", true);
        
        cout << "\n========================================" << endl;
        cout << "   LIBRARY MANAGEMENT SYSTEM" << endl;
        cout << "   Demonstrating OOP Concepts in C++" << endl;
        cout << "========================================" << endl;
        cout << "\nSample data loaded successfully!" << endl;
        cout << "\nSample Login Credentials:" << endl;
        cout << "Student: S001 / pass123" << endl;
        cout << "Faculty: F001 / pass456" << endl;
        cout << "Librarian: L001 / pass789" << endl;
        
    } catch (const LibraryException& e) {
        cerr << "Error loading sample data: " << e.what() << endl;
    }
    
    pauseScreen();
    
    int choice = 0;
    do {
        clearScreen();
        displayMainMenu();
        cout << "\nEnter your choice: ";
        
        if (!(cin >> choice)) {
            cin.clear(); // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            choice = -1; // Set to invalid choice
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        try {
            switch (choice) {
                case 1:
                    loginUser(library);
                    break;
                case 2:
                    registerNewUser(library);
                    break;
                case 3:
                    library->displayAvailableItems();
                    pauseScreen();
                    break;
                case 4:
                    searchItems(library);
                    break;
                case 5:
                    cout << "\nThank you for using the Library Management System!" << endl;
                    break;
                default:
                    cout << "\nInvalid choice. Please try again." << endl;
                    pauseScreen();
            }
        } catch (const LibraryException& e) {
            cerr << "\nError: " << e.what() << endl;
            pauseScreen();
        }
        
    } while (choice != 5);
    
    return 0;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

void displayMainMenu() {
    cout << "\n========================================" << endl;
    cout << "      LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register New User" << endl;
    cout << "3. View Available Items" << endl;
    cout << "4. Search Items" << endl;
    cout << "5. Exit" << endl;
    cout << "========================================" << endl;
}

void loginUser(Library* lib) {
    string userId, password;
    
    cout << "\n=== Login ===" << endl;
    cout << "User ID: ";
    getline(cin, userId);
    cout << "Password: ";
    getline(cin, password);
    
    auto user = lib->authenticateUser(userId, password);
    
    cout << "\nLogin successful! Welcome, " << user->getName() << endl;
    pauseScreen();
    
    string role = user->getRole();
    int menuChoice = 0;
    
    do {
        clearScreen();
        
        if (role == "Student") {
            displayStudentMenu(user);
        } else if (role == "Faculty") {
            displayFacultyMenu(user);
        } else if (role == "Librarian") {
            displayLibrarianMenu(user);
        }
        
        cout << "\nEnter your choice: ";
        if (!(cin >> menuChoice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            menuChoice = -1;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        try {
            switch (menuChoice) {
                case 1: // View Profile
                    user->displayInfo();
                    pauseScreen();
                    break;
                    
                case 2: // Browse Items
                    lib->displayAvailableItems();
                    pauseScreen();
                    break;
                    
                case 3: { // Borrow Item
                    string itemId;
                    cout << "\nEnter Item ID to borrow: ";
                    getline(cin, itemId);
                    lib->borrowItem(user->getUserId(), itemId);
                    pauseScreen();
                    break;
                }
                    
                case 4: { // Return Item
                    string itemId;
                    cout << "\nEnter Item ID to return: ";
                    getline(cin, itemId);
                    lib->returnItem(user->getUserId(), itemId);
                    pauseScreen();
                    break;
                }
                    
                case 5: // My Transactions
                    lib->displayUserTransactions(user->getUserId());
                    pauseScreen();
                    break;
                    
                case 6: // Search
                    searchItems(lib);
                    break;
                    
                case 7: // Admin functions (Librarian only)
                    if (role == "Librarian") {
                        int adminChoice = 0;
                        cout << "\n=== Admin Menu ===" << endl;
                        cout << "1. Add New Item" << endl;
                        cout << "2. View All Users" << endl;
                        cout << "3. View All Items" << endl;
                        cout << "4. View All Transactions" << endl;
                        cout << "5. Overdue Report" << endl;
                        cout << "6. Back" << endl;
                        cout << "Choice: ";
                        
                        if (!(cin >> adminChoice)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            adminChoice = -1;
                        } else {
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        
                        switch (adminChoice) {
                            case 1:
                                addNewItem(lib);
                                break;
                            case 2:
                                lib->displayAllUsers();
                                pauseScreen();
                                break;
                            case 3:
                                lib->displayAllItems();
                                pauseScreen();
                                break;
                            case 4:
                                lib->displayAllTransactions();
                                pauseScreen();
                                break;
                            case 5:
                                lib->generateOverdueReport();
                                pauseScreen();
                                break;
                        }
                    }
                    break;
                    
                case 8: // Logout
                    cout << "\nLogging out..." << endl;
                    break;
                    
                default:
                    cout << "\nInvalid choice!" << endl;
                    pauseScreen();
            }
        } catch (const LibraryException& e) {
            cerr << "\nError: " << e.what() << endl;
            pauseScreen();
        }
        
    } while (menuChoice != 8);
}

void displayStudentMenu(shared_ptr<Person> user) {
    cout << "\n========================================" << endl;
    cout << "      STUDENT MENU" << endl;
    cout << "      Welcome, " << user->getName() << endl;
    cout << "========================================" << endl;
    cout << "1. View My Profile" << endl;
    cout << "2. Browse Available Items" << endl;
    cout << "3. Borrow Item" << endl;
    cout << "4. Return Item" << endl;
    cout << "5. My Transactions" << endl;
    cout << "6. Search Items" << endl;
    cout << "7. [Not Available]" << endl;
    cout << "8. Logout" << endl;
    cout << "========================================" << endl;
}

void displayFacultyMenu(shared_ptr<Person> user) {
    cout << "\n========================================" << endl;
    cout << "      FACULTY MENU" << endl;
    cout << "      Welcome, " << user->getName() << endl;
    cout << "========================================" << endl;
    cout << "1. View My Profile" << endl;
    cout << "2. Browse Available Items" << endl;
    cout << "3. Borrow Item" << endl;
    cout << "4. Return Item" << endl;
    cout << "5. My Transactions" << endl;
    cout << "6. Search Items" << endl;
    cout << "7. [Not Available]" << endl;
    cout << "8. Logout" << endl;
    cout << "========================================" << endl;
}

void displayLibrarianMenu(shared_ptr<Person> user) {
    cout << "\n========================================" << endl;
    cout << "      LIBRARIAN MENU" << endl;
    cout << "      Welcome, " << user->getName() << endl;
    cout << "========================================" << endl;
    cout << "1. View My Profile" << endl;
    cout << "2. Browse Available Items" << endl;
    cout << "3. Borrow Item" << endl;
    cout << "4. Return Item" << endl;
    cout << "5. My Transactions" << endl;
    cout << "6. Search Items" << endl;
    cout << "7. Admin Functions" << endl;
    cout << "8. Logout" << endl;
    cout << "========================================" << endl;
}

void registerNewUser(Library* lib) {
    int userType;
    cout << "\n=== Register New User ===" << endl;
    cout << "1. Student" << endl;
    cout << "2. Faculty" << endl;
    cout << "3. Librarian" << endl;
    cout << "Select user type: ";
    cin >> userType;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string id, name, email, password;
    int age;
    
    cout << "User ID: ";
    getline(cin, id);
    cout << "Name: ";
    getline(cin, name);
    cout << "Email: ";
    getline(cin, email);
    cout << "Password: ";
    getline(cin, password);
    cout << "Age: ";
    cin >> age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if (userType == 1) {
        string studentId, major;
        int year;
        cout << "Student ID: ";
        getline(cin, studentId);
        cout << "Major: ";
        getline(cin, major);
        cout << "Year (1-4): ";
        cin >> year;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        lib->registerStudent(id, name, email, password, age, studentId, major, year);
    } else if (userType == 2) {
        string empId, dept, designation;
        cout << "Employee ID: ";
        getline(cin, empId);
        cout << "Department: ";
        getline(cin, dept);
        cout << "Designation: ";
        getline(cin, designation);
        
        lib->registerFaculty(id, name, email, password, age, empId, dept, designation);
    } else if (userType == 3) {
        string empId, shift;
        cout << "Employee ID: ";
        getline(cin, empId);
        cout << "Shift (Morning/Evening/Night): ";
        getline(cin, shift);
        
        lib->registerLibrarian(id, name, email, password, age, empId, shift);
    }
    
    pauseScreen();
}

void addNewItem(Library* lib) {
    int itemType;
    cout << "\n=== Add New Item ===" << endl;
    cout << "1. Book" << endl;
    cout << "2. Magazine" << endl;
    cout << "3. Journal" << endl;
    cout << "Select item type: ";
    cin >> itemType;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string id, title, publisher;
    int year;
    
    cout << "Item ID: ";
    getline(cin, id);
    cout << "Title: ";
    getline(cin, title);
    cout << "Publisher: ";
    getline(cin, publisher);
    cout << "Publication Year: ";
    cin >> year;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if (itemType == 1) {
        string isbn, author, genre;
        int pages;
        cout << "ISBN: ";
        getline(cin, isbn);
        cout << "Author: ";
        getline(cin, author);
        cout << "Genre: ";
        getline(cin, genre);
        cout << "Total Pages: ";
        cin >> pages;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        lib->addBook(id, title, publisher, year, isbn, author, genre, pages);
    } else if (itemType == 2) {
        int issue;
        string month, category;
        cout << "Issue Number: ";
        cin >> issue;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Month: ";
        getline(cin, month);
        cout << "Category: ";
        getline(cin, category);
        
        lib->addMagazine(id, title, publisher, year, issue, month, category);
    } else if (itemType == 3) {
        int volume;
        string field, editor;
        char peerReviewed;
        cout << "Volume Number: ";
        cin >> volume;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Research Field: ";
        getline(cin, field);
        cout << "Editor: ";
        getline(cin, editor);
        cout << "Peer Reviewed (y/n): ";
        cin >> peerReviewed;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        lib->addJournal(id, title, publisher, year, volume, field, editor, 
                       peerReviewed == 'y' || peerReviewed == 'Y');
    }
    
    pauseScreen();
}

void searchItems(Library* lib) {
    int searchType;
    cout << "\n=== Search Items ===" << endl;
    cout << "1. Search by Title" << endl;
    cout << "2. Search by Type" << endl;
    cout << "Select search type: ";
    cin >> searchType;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if (searchType == 1) {
        string title;
        cout << "Enter title (or part of title): ";
        getline(cin, title);
        
        auto results = lib->searchByTitle(title);
        if (results.empty()) {
            cout << "\nNo items found." << endl;
        } else {
            cout << "\n=== Search Results ===" << endl;
            for (const auto& item : results) {
                item->displayInfo();
                cout << "-------------------------------------------" << endl;
            }
        }
    } else if (searchType == 2) {
        string type;
        cout << "Enter type (Book/Magazine/Journal): ";
        getline(cin, type);
        
        auto results = lib->searchByType(type);
        if (results.empty()) {
            cout << "\nNo items found." << endl;
        } else {
            cout << "\n=== Search Results ===" << endl;
            for (const auto& item : results) {
                item->displayInfo();
                cout << "-------------------------------------------" << endl;
            }
        }
    }
    
    pauseScreen();
}
