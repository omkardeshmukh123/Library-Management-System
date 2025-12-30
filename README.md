# Library Management System

A comprehensive **C++ Library Management System** demonstrating advanced Object-Oriented Programming (OOP) concepts. This project is designed to showcase C++ proficiency for internship applications and technical interviews.

## 🎯 Project Overview

This system manages library operations including user authentication, item management (books, magazines, journals), borrowing/returning transactions, fine calculation, and administrative functions.

## ✨ Key Features

- **User Management**: Support for Students, Faculty, and Librarians with role-based access
- **Item Management**: Books, Magazines, and Journals with detailed cataloging
- **Transaction Processing**: Borrow and return operations with automatic fine calculation
- **Search Functionality**: Search by title or item type
- **Reports**: Overdue items and user activity reports
- **Data Persistence**: File I/O for saving and loading system data
- **Menu-Driven Interface**: Intuitive console-based user interface

## 🏗️ OOP Concepts Demonstrated

### 1. **Abstraction**
- `Person` abstract base class with pure virtual functions
- `LibraryItem` abstract base class defining item interface
- Clean separation between interface and implementation

### 2. **Inheritance**
- **Person Hierarchy**: `Person` → `Student`, `Faculty`, `Librarian`
- **Item Hierarchy**: `LibraryItem` → `Book`, `Magazine`, `Journal`
- Code reuse and specialized behavior in derived classes

### 3. **Polymorphism**
- Virtual functions for runtime polymorphism
- Base class pointers managing derived class objects
- Dynamic method dispatch (`displayInfo()`, `getRole()`, etc.)

### 4. **Encapsulation**
- Private data members with public getters/setters
- Protected members for inheritance
- Information hiding and controlled access

### 5. **Design Patterns**
- **Singleton Pattern**: `Library` class for centralized management
- Single instance ensuring data consistency

### 6. **Exception Handling**
- Custom exception hierarchy inheriting from `std::exception`
- Specific exceptions: `ItemNotFoundException`, `UserNotFoundException`, etc.
- Graceful error handling throughout the application

### 7. **STL Usage**
- `std::vector` for transaction storage
- `std::map` for user and item lookups
- `std::shared_ptr` for automatic memory management
- STL algorithms for searching and filtering

### 8. **File I/O**
- Data serialization for persistence
- Loading and saving system state

## 📁 Project Structure

```
CPP Project/
├── include/
│   ├── Exceptions.h      # Custom exception classes
│   ├── Person.h          # Abstract Person base class
│   ├── Student.h         # Student derived class
│   ├── Faculty.h         # Faculty derived class
│   ├── Librarian.h       # Librarian derived class
│   ├── LibraryItem.h     # Abstract LibraryItem base class
│   ├── Book.h            # Book derived class
│   ├── Magazine.h        # Magazine derived class
│   ├── Journal.h         # Journal derived class
│   ├── Transaction.h     # Transaction management
│   └── Library.h         # Main library system (Singleton)
├── src/
│   ├── main.cpp          # Application entry point
│   ├── Person.cpp        # Person implementation
│   ├── Student.cpp       # Student implementation
│   ├── Faculty.cpp       # Faculty implementation
│   ├── Librarian.cpp     # Librarian implementation
│   ├── LibraryItem.cpp   # LibraryItem implementation
│   ├── Book.cpp          # Book implementation
│   ├── Magazine.cpp      # Magazine implementation
│   ├── Journal.cpp       # Journal implementation
│   ├── Transaction.cpp   # Transaction implementation
│   └── Library.cpp       # Library implementation
├── CMakeLists.txt        # Build configuration
└── README.md             # This file
```

## 🚀 Building and Running

### Prerequisites
- C++14 or later compiler (GCC, Clang, MSVC)
- CMake 3.10 or later

### Build Instructions

**Using CMake:**
```bash
# Create build directory
mkdir build
cd build

# Generate build files
cmake ..

# Build the project
cmake --build .

# Run the application
./bin/LibrarySystem    # On Linux/Mac
.\bin\LibrarySystem    # On Windows
```

**Alternative (g++ on Windows):**
```bash
g++ -std=c++14 -I./include src/*.cpp -o LibrarySystem.exe
.\LibrarySystem.exe
```

## 🎮 Usage

### Sample Login Credentials
The system comes with pre-loaded sample data:

- **Student**: `S001` / `pass123`
- **Faculty**: `F001` / `pass456`
- **Librarian**: `L001` / `pass789`

### Main Features by Role

**Student/Faculty:**
- View profile
- Browse available items
- Borrow and return items
- View transaction history
- Search items by title or type

**Librarian (Additional):**
- Add new items to the library
- View all users and items
- Generate reports (overdue items, user activity)
- Full administrative access

## 💡 Technical Highlights

### Smart Memory Management
- Uses `std::shared_ptr` for automatic memory management
- No manual `new`/`delete` operations
- Prevents memory leaks

### Exception Safety
- All operations are exception-safe
- Proper resource cleanup in destructors
- Comprehensive error messages

### Fine Calculation
- Automatic calculation based on item type:
  - Books: $0.50/day
  - Magazines: $0.25/day
  - Journals: $0.75/day
- Date-based overdue tracking

### Role-Based Privileges
- Students: 5 items, 14 days
- Faculty: 10 items, 30 days
- Librarians: 15 items, 60 days

## 📊 Class Hierarchy Diagram

```
Person (Abstract)
├── Student (5 items, 14 days)
├── Faculty (10 items, 30 days)
└── Librarian (15 items, 60 days, Admin access)

LibraryItem (Abstract)
├── Book ($0.50/day late fee)
├── Magazine ($0.25/day late fee)
└── Journal ($0.75/day late fee)

Library (Singleton)
├── manages → Person instances
├── manages → LibraryItem instances
└── tracks → Transaction history
```

## 🎯 Interview Discussion Points

1. **Why use abstract base classes?**
   - Enforces common interface across derived classes
   - Enables polymorphism for uniform handling
   - Prevents instantiation of incomplete types

2. **Singleton Pattern choice?**
   - Single source of truth for library data
   - Prevents data inconsistency
   - Global access point for library operations

3. **Smart pointers vs raw pointers?**
   - Automatic memory management
   - Exception safety
   - Clear ownership semantics

4. **STL containers choice?**
   - `map` for O(log n) lookups by ID
   - `vector` for efficient sequential access
   - Type-safe, well-tested implementations

## 🔮 Future Enhancements

- Database integration (SQLite/MySQL)
- GUI using Qt or wxWidgets
- Network capability for multi-client access
- Advanced search with filters
- Email notifications for due dates
- Book reservation system
- Digital library integration

## 👨‍💻 Author

Created as a resume-worthy C++ project demonstrating OOP principles and modern C++ best practices.

## 📝 License

This project is created for educational and portfolio purposes.

---

**Note**: This project demonstrates industry-standard C++ practices including RAII, exception safety, const-correctness, and modern C++ features suitable for professional development roles.
