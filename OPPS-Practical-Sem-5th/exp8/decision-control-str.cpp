// Experiment 8 — Decision & Control Structures (Robust Menu-Driven App)

// Question (brief):
// Create a menu-driven CLI that demonstrates control structures (if/switch/for/while/do-while), break/continue, recursion vs iteration, and input validation. Provide options for: arithmetic, factorial, Fibonacci (iterative & recursive), prime check, string palindrome, and exit.


// exp8.cpp
#include <iostream>
#include <string>
#include <cmath>
#include <limits>
using namespace std;

long long factorialIter(int n) {
    long long r = 1;
    for (int i = 2; i <= n; ++i) r *= i;
    return r;
}
long long factorialRec(int n) {
    return (n <= 1) ? 1 : n * factorialRec(n - 1);
}

long long fibonacciIter(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) { long long t = a + b; a = b; b = t; }
    return b;
}
long long fibonacciRec(int n) {
    if (n <= 1) return n;
    return fibonacciRec(n-1) + fibonacciRec(n-2); // exponential time
}

bool isPrime(long long x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0) return false;
    for (long long i = 3; i*i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

bool isPalindrome(const string &s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}

int readInt(const string &prompt) {
    int n;
    while (true) {
        cout << prompt;
        if (cin >> n) return n;
        cout << "Invalid number. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    using std::cout; using std::cin; using std::endl;
    int choice;
    do {
        cout << "\n--- Menu ---\n"
             << "1) Arithmetic (+ - * /)\n"
             << "2) Factorial (iter & rec)\n"
             << "3) Fibonacci (iter & rec)\n"
             << "4) Prime check\n"
             << "5) String palindrome\n"
             << "6) Exit\n"
             << "Choose: ";
        choice = readInt("");
        switch (choice) {
            case 1: {
                double a, b; char op;
                cout << "Enter: a op b  (e.g. 3.5 * 2)\n";
                if (!(cin >> a >> op >> b)) { cout << "Bad input\n"; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(),'\n'); break; }
                if (op == '+') cout << (a + b) << '\n';
                else if (op == '-') cout << (a - b) << '\n';
                else if (op == '*') cout << (a * b) << '\n';
                else if (op == '/') {
                    if (b == 0) cout << "Division by zero\n"; else cout << (a / b) << '\n';
                } else cout << "Unknown operator\n";
                break;
            }
            case 2: {
                int n = readInt("Enter non-negative integer for factorial: ");
                if (n < 0) { cout << "Negative not allowed\n"; break; }
                cout << "Iterative: " << factorialIter(n) << "\n";
                cout << "Recursive: " << factorialRec(n) << "\n";
                break;
            }
            case 3: {
                int n = readInt("Enter n (>=0) for Fibonacci: ");
                if (n < 0) { cout << "Negative not allowed\n"; break; }
                cout << "Iterative: " << fibonacciIter(n) << "\n";
                cout << "Recursive (slow): " << fibonacciRec(n) << "\n";
                break;
            }
            case 4: {
                long long x;
                cout << "Enter integer to test primality: ";
                if (!(cin >> x)) { cout << "Bad input\n"; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(),'\n'); break; }
                cout << (isPrime(x) ? "Prime\n" : "Not prime\n");
                break;
            }
            case 5: {
                cout << "Enter a string (no spaces): ";
                string s; if (!(cin >> s)) { cin.clear(); break; }
                cout << (isPalindrome(s) ? "Palindrome\n" : "Not palindrome\n");
                break;
            }
            case 6:
                cout << "Exiting.\n"; break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
    return 0;
}

// Explanation — focused, essential points

// Menu loop: do { ... } while(choice != 6); gives a repeatable menu until exit.

// switch statement: selects action efficiently; each case ends with break to avoid fall-through.

// Input validation: readInt ensures numeric input; when cin fails we clear() and ignore() to remove bad tokens.

// Loops used:

// for in factorialIter and prime checking.

// while in palindrome and menu loops.

// Recursion vs Iteration:

// factorialRec and fibonacciRec are recursive; recursion is elegant but can be slow/deep (stack overflow risk for large n).

// Iterative versions are efficient and safe for large n.

// break / continue:

// break used to exit switch branches and loop cases.

// continue can be used inside loops to skip to next iteration (not used here but applicable in searches/filters).

// Error handling: Basic checks for division by zero, negative inputs for factorial/fibonacci, and bad parsing.