// Experiment 4 — Inheritance & Visibility
// Question (brief):

// Create three classes (Person, Student, ResearchStudent) to demonstrate:

// public vs protected inheritance

// access to public, protected, and private members

// method overriding with virtual

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n): name(n) {}
    virtual void who() const { cout << "Person: " << name << "\n"; }
};

class Student : public Person {        // public inheritance
public:
    int roll;
    Student(string n, int r): Person(n), roll(r) {}
    void who() const override { cout << "Student: " << name << " (" << roll << ")\n"; }
};

class ResearchStudent : protected Student { // protected inheritance
    string topic;
public:
    ResearchStudent(string n, int r, string t)
        : Student(n, r), topic(t) {}
    void show() const { cout << "Research: " << name << ", topic=" << topic << "\n"; }
};

int main() {
    Student s("Alice", 101);
    s.who();               // OK (public inheritance)

    Person* p = &s;        // OK (Student IS-A Person)
    p->who();              // runtime polymorphism (virtual)

    ResearchStudent rs("Bob", 202, "AI");
    rs.show();             // OK

    // rs.roll;            // ERROR: protected inheritance hides Student's public members
    // Person* p2 = &rs;   // ERROR: cannot convert (protected inheritance)

    return 0;
}



// Explanation (very short)

// 1. Person → Student (public inheritance)

// Student is-a Person.

// You can do Person* p = &s.

// who() is overridden → runtime polymorphism via virtual.

// 2. Student → ResearchStudent (protected inheritance)

// All public members of Student become protected inside ResearchStudent.

// So from main, rs.roll is not allowed.

// Also Person* p2 = &rs; fails because protected inheritance hides the is-a relationship.

// 3. Why protected is used
// To reuse Student’s code but not expose it as a public type.
// ResearchStudent uses Student’s features internally but doesn’t behave as a Student externally.