// Experiment 13:
// Dynamic Memory Allocation using new and delete (Very Short Program + Explanation)

#include <iostream>
using namespace std;

int main() {
    int *p = new int;       // allocate memory for 1 integer
    *p = 10;
    cout << "Value = " << *p << endl;
    delete p;              // free memory

    int n;
    cout << "Enter array size: ";
    cin >> n;

    int *arr = new int[n]; // dynamic array allocation
    for(int i = 0; i < n; i++) arr[i] = i + 1;

    cout << "Array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    delete[] arr;          // free array memory
    return 0;
}


// Very Short Explanation
// Concept         	            Meaning
// new	                 Allocates memory at runtime from heap.
// delete	            Releases memory allocated with new.
// new[]	            Allocates array dynamically.
// delete[]	        Frees dynamically allocated array.
// Why use?        	When size is unknown at compile time.
// Importance	        Prevents memory wastage & enables flexible allocation.
// Don't forget	      Always use delete or delete[] to avoid memory leaks.