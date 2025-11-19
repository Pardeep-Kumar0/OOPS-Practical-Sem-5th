// Experiment 6 — Variables, Datatypes & Reference Variables

// Question (short)

// Write a C++ program to:

// Demonstrate use of different data types and sizeof.

// Compare pass by value vs pass by reference using a swap function.

// Show how modifying a reference affects the original variable.

#include <iostream>
using namespace std;

// Pass by value (copies)
void swapVal(int a, int b) {
    int temp = a; a = b; b = temp;
}

// Pass by reference (direct change)
void swapRef(int &a, int &b) {
    int temp = a; a = b; b = temp;
}

int main() {
    cout << "sizeof(int): " << sizeof(int) << " bytes\n";
    cout << "sizeof(double): " << sizeof(double) << " bytes\n";

    int x = 10, y = 20;
    cout << "\nBefore swapVal: x=" << x << ", y=" << y << "\n";
    swapVal(x, y);
    cout << "After swapVal:  x=" << x << ", y=" << y << " (no change)\n";

    cout << "\nBefore swapRef: x=" << x << ", y=" << y << "\n";
    swapRef(x, y);
    cout << "After swapRef:  x=" << x << ", y=" << y << " (changed)\n";

    int &ref = x;     // reference to x
    ref = 99;         // modifies x directly
    cout << "\nAfter ref change: x=" << x << " (ref=" << ref << ")\n";
}


// Explanation (clear & simple)
// ✔ Data types

// Each data type uses different memory. sizeof(type) tells how many bytes it occupies.

// ✔ Reference vs Value
// Feature	            Pass by Value	       Pass by Reference
// Method	            void f(int x)	       void f(int &x)
// What happens	       Copy of variable	       Direct access
// Changes original?	   ❌ No	               ✅ Yes
// Memory use	            More	              Less
// Performance	           Slower	              Faster (especially for big objects)

// Reference is just an alias (another name) for the same variable.
// So modifying it changes the original.

// ✔ Reference Variable Example
// int x = 5;
// int &r = x;   // r is another name of x
// r = 10;       // changes x also

// 4. Key Notes

// Use & in function parameters to avoid copying & improve performance.

// Use const int & if you don’t want to modify.

// References must be initialized when declared.

// They cannot be changed to refer to another variable later.

// 5. Optional Extension

// Try this:

// void changeConst(const int &x) {
//     // x = 10;  // ERROR: x is read-only now
// }


// Helps understand const correctness.