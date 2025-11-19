// Experiment: 12
// Abstract Classes and Virtual Base Classes in C++
// Abstract class
// ✔ Virtual base class (solves diamond problem)

#include <iostream>
using namespace std;

// Abstract class (pure virtual)
class Shape {
public:
    virtual void draw() = 0; // pure virtual
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing Circle\n"; }
};

// Virtual base class example (diamond problem)
class A {
public:
    int x;
};

class B : virtual public A {};   // virtual inheritance
class C : virtual public A {};   // virtual inheritance
class D : public B, public C {}; // only ONE A shared

int main() {
    // Abstract class
    Shape* s = new Circle();
    s->draw();
    delete s;

    // Virtual base
    D obj;
    obj.x = 10;    // no ambiguity due to virtual inheritance
    cout << "Value of x = " << obj.x << endl;
}

//Explanation: 
// Concept	                       Meaning
// Abstract class               Has pure virtual function → cannot create object of it
// Virtual function             Allows overriding
// Virtual inheritance          Prevents duplicate base copies in diamond inheritance   
// Result                       Only one A exists inside D, so obj.x is unambiguous 

