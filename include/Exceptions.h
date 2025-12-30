#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

/**
 * Custom exception classes for Library Management System
 * Demonstrates exception handling and inheritance from std::exception
 */

// Base exception class for all library-related exceptions
class LibraryException : public std::exception {
protected:
    std::string message;
public:
    explicit LibraryException(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
    virtual ~LibraryException() noexcept {}
};

// Exception for when a library item is not found
class ItemNotFoundException : public LibraryException {
public:
    explicit ItemNotFoundException(const std::string& itemId) 
        : LibraryException("Item not found: " + itemId) {}
};

// Exception for when a user is not found
class UserNotFoundException : public LibraryException {
public:
    explicit UserNotFoundException(const std::string& userId) 
        : LibraryException("User not found: " + userId) {}
};

// Exception for invalid operations
class InvalidOperationException : public LibraryException {
public:
    explicit InvalidOperationException(const std::string& operation) 
        : LibraryException("Invalid operation: " + operation) {}
};

// Exception for file I/O errors
class FileIOException : public LibraryException {
public:
    explicit FileIOException(const std::string& filename) 
        : LibraryException("File I/O error: " + filename) {}
};

// Exception for authentication failures
class AuthenticationException : public LibraryException {
public:
    explicit AuthenticationException(const std::string& reason) 
        : LibraryException("Authentication failed: " + reason) {}
};

// Exception for when item is already borrowed
class ItemAlreadyBorrowedException : public LibraryException {
public:
    explicit ItemAlreadyBorrowedException(const std::string& itemId) 
        : LibraryException("Item already borrowed: " + itemId) {}
};

// Exception for when borrowing limit is exceeded
class BorrowLimitExceededException : public LibraryException {
public:
    explicit BorrowLimitExceededException(const std::string& reason) 
        : LibraryException("Borrow limit exceeded: " + reason) {}
};

#endif // EXCEPTIONS_H
