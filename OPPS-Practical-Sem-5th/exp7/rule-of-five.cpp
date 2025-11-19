// Experiment 7 — Rule of Three / Rule of Five
// 1. Question (brief)

// Create a class SimpleString that manages a dynamic char array using new.
// Demonstrate:

// Default constructor

// Parameter constructor

// Copy constructor

// Copy assignment operator

// Destructor

// Then improve using move constructor and move assignment operator to show modern C++ efficiency.


#include <iostream>
#include <cstring>
using namespace std;

class SimpleString {
    char* data;
    size_t len;

public:
    // Default constructor
    SimpleString() : data(nullptr), len(0) {}

    // Parameter constructor
    SimpleString(const char* s) {
        len = strlen(s);
        data = new char[len + 1];
        strcpy(data, s);
    }

    // Copy constructor (deep copy)
    SimpleString(const SimpleString& other) {
        len = other.len;
        data = new char[len + 1];
        strcpy(data, other.data);
        cout << "Copy constructor called\n";
    }

    // Copy assignment operator
    SimpleString& operator=(const SimpleString& other) {
        cout << "Copy assignment called\n";
        if (this != &other) {   // avoid self copy
            delete[] data;
            len = other.len;
            data = new char[len + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Move constructor
    SimpleString(SimpleString&& other) noexcept {
        cout << "Move constructor called\n";
        data = other.data;
        len = other.len;
        other.data = nullptr; // release ownership
        other.len = 0;
    }

    // Move assignment
    SimpleString& operator=(SimpleString&& other) noexcept {
        cout << "Move assignment called\n";
        if (this != &other) {
            delete[] data;
            data = other.data;
            len = other.len;
            other.data = nullptr;
            other.len = 0;
        }
        return *this;
    }

    // Destructor
    ~SimpleString() {
        cout << "Destructor called\n";
        delete[] data;
    }

    const char* c_str() const { return data; }
};

int main() {
    SimpleString a("Hello");
    SimpleString b = a;         // calls copy constructor
    SimpleString c("World");
    c = a;                      // calls copy assignment

    SimpleString d = move(a);   // calls move constructor
    SimpleString e("Test");
    e = move(b);                // calls move assignment

    cout << "d: " << d.c_str() << "\n";
}



// Explanation (concept-focused)
// 🔹 Why this experiment?

// When a class manages resources (like heap memory),
// you must define special functions to:

// Prevent memory leaks

// Avoid shallow copies

// Improve performance with move semantics

// 🔹 Rule of Three

// If your class needs any one of these → you must define ALL THREE:

// Destructor (~SimpleString())

// Copy constructor

// Copy assignment operator

// Because default versions perform shallow copy, leading to double free or crashes.

// 🔹 Rule of Five (modern C++11+)

// In addition to the above three, also implement:
// 4. Move constructor
// 5. Move assignment operator

// Move semantics allow fast transfer instead of slow deep copy.

// Example:

// vector<SimpleString> v;
// v.push_back(SimpleString("temp"));
// // move constructor called → efficient

// 4. Key Insights to Remember (for viva/exam)

// ✔ Deep vs shallow copy
// ✔ this != &other to avoid self-copy
// ✔ Use std::move() to trigger move instead of copy
// ✔ After moving, set source pointer to nullptr
// ✔ Destructor must release memory only once
// ✔ Move improves performance in STL containers

// 5. Optional improvements

// Use std::unique_ptr<char[]> instead of raw new

// Add bounds check or length getter

// Replace C-style string with std::string (safer)