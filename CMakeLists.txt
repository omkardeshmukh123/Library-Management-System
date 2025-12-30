cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(LibrarySystem
    src/main.cpp
    src/Person.cpp
    src/Student.cpp
    src/Faculty.cpp
    src/Librarian.cpp
    src/LibraryItem.cpp
    src/Book.cpp
    src/Magazine.cpp
    src/Journal.cpp
    src/Transaction.cpp
    src/Library.cpp
)

# Include directories
target_include_directories(LibrarySystem PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Set output directory
set_target_properties(LibrarySystem PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Platform-specific settings
if(MSVC)
    target_compile_options(LibrarySystem PRIVATE /W4)
else()
    target_compile_options(LibrarySystem PRIVATE -Wall -Wextra -pedantic)
endif()
