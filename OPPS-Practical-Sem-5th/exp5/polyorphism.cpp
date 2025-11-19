// Experiment 5 — Polymorphism

// 1. Question (short)
// Create a base class Shape with a virtual function area().
// Create derived classes: Circle and Rectangle.
// Store them using base-class pointers and call area() to demonstrate runtime polymorphism.

#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;   // pure virtual → abstract class
    virtual void who() const { cout << "Shape\n"; }
    virtual ~Shape() {}                // virtual destructor
};

class Circle : public Shape {
    double r;
public:
    Circle(double rad) : r(rad) {}
    double area() const override { return M_PI * r * r; }
    void who() const override { cout << "Circle\n"; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double a, double b): w(a), h(b) {}
    double area() const override { return w * h; }
    void who() const override { cout << "Rectangle\n"; }
};

int main() {
    Shape* s1 = new Circle(5);
    Shape* s2 = new Rectangle(4, 6);

    s1->who();  cout << "Area: " << s1->area() << "\n";
    s2->who();  cout << "Area: " << s2->area() << "\n";

    delete s1;
    delete s2;
}


// 3. Explanation — What is Polymorphism? (very clear)
// Meaning:

// Polymorphism means one interface → many forms.

// In C++, it allows a base class pointer/reference to call functions of derived classes at runtime.

// Example:

// Shape* s = new Circle(5);
// s->area();   // calls Circle::area()


// Even though s is a Shape*, it runs the Circle version.

// Why?

// Because of virtual functions.

// virtual double area() const;

// This tells the compiler:
// “Choose the function version at runtime depending on the actual object.”

// Types of Polymorphism in C++

// Compile-time Polymorphism

// Function overloading

// Operator overloading

// Resolved at compile time

// Runtime Polymorphism

// Virtual functions

// Abstract classes

// Resolved at runtime

// This experiment focuses on runtime polymorphism.

// What this Experiment Teaches You

// How virtual enables dynamic dispatch

// Why we need a virtual destructor (to delete derived objects safely)

// How to use base pointers to refer to different shapes

// How abstract classes enforce a common interface (area())