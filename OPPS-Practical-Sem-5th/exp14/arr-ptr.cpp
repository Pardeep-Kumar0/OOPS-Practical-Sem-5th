// Explanation : 
// Array
// ✔ Pointer
// ✔ Passing array of objects to a function
// ✔ this pointer
// ✔ Basic function usage

#include <iostream>
using namespace std;

class Student {
    int roll;
public:
    void set(int r) { this->roll = r; }   // using this pointer
    void show() { cout << "Roll = " << roll << endl; }
};

// function to display array of objects
void display(Student s[], int n) {         // passing array of objects
    for(int i = 0; i < n; i++) s[i].show();
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student *ptr = new Student[n];         // dynamic array of objects

    for(int i = 0; i < n; i++) {
        int r;
        cout << "Enter roll no for student " << i + 1 << ": ";
        cin >> r;
        ptr[i].set(r);                     // setting value using pointer
    }

    cout << "\nDisplaying Student Records:\n";
    display(ptr, n);                       // passing array to function

    delete[] ptr;                          // free memory
    return 0;
}


// 1. Class & this pointer
// class Student {
//     int roll;
// public:
//     void set(int r) { this->roll = r; }
//     void show() { cout << "Roll = " << roll << endl; }
// };


// class Student defines a type with one data member: roll.

// this is an implicit pointer inside every non-static member function.

// Type: Student* const this

// this->roll = r; means: set the roll of current object.

// You could also write roll = r; (same thing), but using this-> helps you understand that a hidden pointer is used.

// 2. Passing array of objects to a function
// void display(Student s[], int n) {
//     for(int i = 0; i < n; i++) s[i].show();
// }


// Function parameter Student s[] is actually treated as Student* s.

// You pass address of first element of array.

// Inside the function, s[i] uses pointer arithmetic to access each object.

// This shows “array of objects passed to function” clearly.

// 3. Dynamic array of objects using pointer
// int n;
// cout << "Enter number of students: ";
// cin >> n;

// Student *ptr = new Student[n];  // dynamic array of objects


// n is decided at runtime (user input).

// new Student[n] allocates memory for n Student objects on the heap.

// ptr points to the first Student object.

// This demonstrates dynamic memory allocation for array of objects.

// 4. Using array + pointer syntax
// for(int i = 0; i < n; i++) {
//     int r;
//     cout << "Enter roll no for student " << i + 1 << ": ";
//     cin >> r;
//     ptr[i].set(r);   // same as (*(ptr + i)).set(r);
// }


// ptr[i] is array-style access using pointer ptr.

// Internally, ptr[i] means *(ptr + i) (pointer arithmetic).

// Each element is an object, so you can call set() and show().

// 5. Passing dynamic array of objects
// display(ptr, n);


// ptr (type Student*) is passed to display().

// In display, parameter Student s[] receives that pointer.

// The function iterates and calls show() on each object.

// 6. Memory cleanup
// delete[] ptr;


// new[] must always be paired with delete[].

// Frees all Student objects allocated.

// Avoids memory leak.

// 7. Concepts covered (one-line recap)

// Array: collection of elements of same type (Student here).

// Pointer: variable holding address (Student* ptr).

// Dynamic allocation: new Student[n] → size decided at runtime.

// Array of objects: Student *ptr points to multiple Student objects.

// Pass array to function: void display(Student s[], int n).

// this pointer: refers to current object inside member functions.