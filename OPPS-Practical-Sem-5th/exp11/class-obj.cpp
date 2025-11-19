// Experiment: 11 — Classes & Objects

#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}      // constructor
    void showName() { cout << "Name: " << name << endl; }
};

// Derived class
class Student : public Person {
    int roll;
public:
    Student(string n, int r) : Person(n), roll(r) {}
    void showDetails() {
        showName();                    // access base class method
        cout << "Roll: " << roll << endl;
    }
};

int main() {
    Student s("Alice", 101);   // object creation
    s.showDetails();           // access members using . operator

    Person p("Bob");           // base class object
    p.showName();

    return 0;
}

// Explanation (very short)
// 1. Class: A blueprint for creating objects. It defines attributes (data members) and behaviors (member functions).
// 2. Object: An instance of a class. It holds actual data and can use
//    the functions defined in the class.
// 3. Accessing Members: Use the dot operator (.) to access data members and
//    member functions of an object.
// 4. Inheritance: A derived class (Student) can inherit from a base class (Person),
//    allowing code reuse and hierarchical relationships.