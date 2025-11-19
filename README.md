# Object-Oriented Programming (OOP) Practicals - Semester 5

Welcome to the **OOP Practicals Repository** for Semester 5! This repository contains 14 comprehensive C++ experiments designed to teach fundamental and advanced concepts of Object-Oriented Programming.

## 📚 Table of Contents

- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [Repository Structure](#repository-structure)
- [Experiments List](#experiments-list)
- [Compilation and Execution](#compilation-and-execution)
- [Topics Covered](#topics-covered)
- [Getting Started](#getting-started)
- [Contributing](#contributing)

## 🎯 Overview

This repository contains practical implementations of various OOP concepts using C++. Each experiment is self-contained in its own directory with complete source code and executable files. The experiments progress from basic OOP concepts to advanced topics like STL, file handling, and memory management.

## 🔧 Prerequisites

To compile and run these programs, you need:

- **C++ Compiler**: GCC (g++) version 7.0 or higher, or any C++14/17 compatible compiler
- **Operating System**: Windows, Linux, or macOS
- **Text Editor/IDE**: VS Code, Code::Blocks, Dev-C++, or any C++ IDE
- **Basic Knowledge**: Understanding of C programming and basic programming concepts

### Installing GCC on Different Platforms

**Windows:**
- Install MinGW or use WSL (Windows Subsystem for Linux)
- Download from: http://mingw.org/

**Linux:**
```bash
sudo apt-get update
sudo apt-get install g++
```

**macOS:**
```bash
xcode-select --install
```

## 📁 Repository Structure

```
OOPS-Practical-Sem-5th/
│
├── README.md                          # This file
│
└── OPPS-Practical-Sem-5th/
    ├── exp1/                          # OOP vs POP Comparison
    ├── exp2/                          # C and C++ Integration
    ├── exp3/                          # Encapsulation & Abstraction
    ├── exp4/                          # Inheritance & Visibility
    ├── exp5/                          # Polymorphism
    ├── exp6/                          # Variables & References
    ├── exp7/                          # Rule of Three/Five
    ├── exp8/                          # Control Structures
    ├── exp9/                          # STL Containers
    ├── exp10/                         # File Handling - Student Database
    ├── exp11/                         # Classes & Objects
    ├── exp12/                         # Abstract & Virtual Base Classes
    ├── exp13/                         # Dynamic Memory Allocation
    └── exp14/                         # Arrays, Pointers & Objects
```

## 📝 Experiments List

### Experiment 1: OOP vs POP Comparison
**Files:** `exp1-oop.cpp`, `exp1-pop.cpp`
- **Topics**: Object-Oriented vs Procedure-Oriented Programming
- **Concepts**: Classes, Objects, Encapsulation
- **Description**: Implements a Student management system in both OOP and POP paradigms to demonstrate the advantages of OOP including data hiding, modularity, and code reusability.

### Experiment 2: C and C++ Integration
**Files:** `main.cpp`, `adder.c`
- **Topics**: C and C++ interoperability
- **Concepts**: `extern "C"`, Compilation steps, Linking
- **Description**: Demonstrates how to compile and call a C function from C++ code using extern "C" linkage specification. Shows compilation and linking process.

### Experiment 3: Encapsulation & Abstraction
**Files:** `abs-enp.cpp`
- **Topics**: Data hiding, Abstraction, Encapsulation
- **Concepts**: BankAccount class with private members
- **Description**: Implements a BankAccount class that encapsulates account data (account number, owner, balance) with methods for deposit, withdraw, transfer, and demonstrates error handling for invalid operations.

### Experiment 4: Inheritance & Visibility
**Files:** `inheritance-and-visibility.cpp`
- **Topics**: Inheritance, Access specifiers
- **Concepts**: Public vs Protected inheritance, Method overriding
- **Description**: Creates a hierarchy of Person → Student → ResearchStudent classes to demonstrate inheritance types, access to public/protected/private members, and virtual method overriding.

### Experiment 5: Polymorphism
**Files:** `polyorphism.cpp`
- **Topics**: Runtime polymorphism, Virtual functions
- **Concepts**: Abstract classes, Pure virtual functions
- **Description**: Implements a Shape base class with derived Circle and Rectangle classes. Demonstrates runtime polymorphism using base-class pointers and virtual functions.

### Experiment 6: Variables, Data Types & References
**Files:** `vari-datatypes.cpp`
- **Topics**: Data types, Reference variables
- **Concepts**: Pass by value vs Pass by reference
- **Description**: Explores different data types, sizeof operator, and demonstrates the difference between pass-by-value and pass-by-reference using swap functions.

### Experiment 7: Rule of Three/Five
**Files:** `rule-of-five.cpp`
- **Topics**: Resource management, RAII
- **Concepts**: Copy constructor, Copy assignment, Move semantics
- **Description**: Implements SimpleString class managing dynamic memory. Demonstrates the Rule of Three (constructor, copy constructor, destructor) and Rule of Five (adding move constructor and move assignment).

### Experiment 8: Decision & Control Structures
**Files:** `decision-control-str.cpp`
- **Topics**: Control flow, Recursion vs Iteration
- **Concepts**: if/switch/for/while, break/continue
- **Description**: Menu-driven application demonstrating various control structures, implementing factorial, Fibonacci (both iterative and recursive), prime checking, and palindrome verification.

### Experiment 9: STL Containers & Algorithms
**Files:** `STC-Vec-set-map.cpp`
- **Topics**: Standard Template Library (STL)
- **Concepts**: vector, set, map, STL algorithms
- **Description**: Demonstrates use of STL containers (vector, set, map) and algorithms (sort, find, count). Implements unique value extraction and frequency counting.

### Experiment 10: File Handling - Student Database
**Files:** `studentDB.cpp`, `students.txt`
- **Topics**: File I/O, Data persistence
- **Concepts**: fstream, File operations, CRUD operations
- **Description**: Complete student database system with add, delete, edit, search, and sort functionalities. Implements file save/load operations for data persistence.

### Experiment 11: Classes & Objects Basics
**Files:** `class-obj.cpp`
- **Topics**: Class definition, Object creation
- **Concepts**: Constructors, Member functions, Inheritance basics
- **Description**: Simple demonstration of classes and objects with Person base class and Student derived class, showing basic inheritance and member access.

### Experiment 12: Abstract & Virtual Base Classes
**Files:** `abstract-virtual-class.cpp`
- **Topics**: Abstract classes, Diamond problem
- **Concepts**: Pure virtual functions, Virtual inheritance
- **Description**: Demonstrates abstract classes with pure virtual functions and solves the diamond problem using virtual base classes.

### Experiment 13: Dynamic Memory Allocation
**Files:** `dynamic-memory.cpp`
- **Topics**: Heap memory management
- **Concepts**: new/delete operators, Dynamic arrays
- **Description**: Shows dynamic memory allocation for single variables and arrays using new/delete operators, emphasizing proper memory deallocation.

### Experiment 14: Arrays, Pointers & Objects
**Files:** `arr-ptr.cpp`
- **Topics**: Arrays of objects, Pointers
- **Concepts**: this pointer, Passing arrays to functions
- **Description**: Demonstrates arrays of objects, dynamic allocation of object arrays, this pointer usage, and passing array of objects to functions.

## 🔨 Compilation and Execution

### General Compilation

For most experiments (single file):
```bash
# Navigate to experiment directory
cd OPPS-Practical-Sem-5th/exp<number>/

# Compile
g++ <filename>.cpp -o program

# Run
./program        # Linux/macOS
program.exe      # Windows
```

### Specific Examples

**Experiment 1 (OOP version):**
```bash
cd OPPS-Practical-Sem-5th/exp1/
g++ exp1-oop.cpp -o student_oop
./student_oop
```

**Experiment 2 (C and C++ integration):**
```bash
cd OPPS-Practical-Sem-5th/exp2/
# Compile C file separately
gcc -c adder.c -o adder.o
# Compile C++ file
g++ -c main.cpp -o main.o
# Link both
g++ main.o adder.o -o prog
./prog

# Or compile in one command:
g++ main.cpp adder.c -o prog
./prog
```

**Experiment 10 (Student Database with file handling):**
```bash
cd OPPS-Practical-Sem-5th/exp10/
g++ studentDB.cpp -o studentDB
./studentDB
# The program will create/read students.txt file
```

### Using C++14/17 Features

Some programs may benefit from newer C++ standards:
```bash
g++ -std=c++14 filename.cpp -o program
# or
g++ -std=c++17 filename.cpp -o program
```

## 📖 Topics Covered

This practical series comprehensively covers:

### Core OOP Concepts
- ✅ Classes and Objects
- ✅ Encapsulation and Data Hiding
- ✅ Abstraction
- ✅ Inheritance (Single, Multiple, Hierarchical)
- ✅ Polymorphism (Compile-time and Runtime)
- ✅ Virtual Functions and Pure Virtual Functions
- ✅ Abstract Classes
- ✅ Virtual Base Classes (Diamond Problem Solution)

### C++ Specific Features
- ✅ Constructors and Destructors
- ✅ Copy Constructor and Assignment Operator
- ✅ Move Semantics (Move Constructor and Move Assignment)
- ✅ The `this` Pointer
- ✅ Reference Variables
- ✅ Function Overloading
- ✅ Operator Overloading (where applicable)

### Memory Management
- ✅ Dynamic Memory Allocation (`new`/`delete`)
- ✅ RAII (Resource Acquisition Is Initialization)
- ✅ Rule of Three and Rule of Five
- ✅ Memory Leaks Prevention

### Advanced Topics
- ✅ Standard Template Library (STL)
  - Containers: `vector`, `set`, `map`
  - Algorithms: `sort`, `find`, `count`
- ✅ File Handling (`fstream`, `ifstream`, `ofstream`)
- ✅ Exception Handling
- ✅ Control Structures (if, switch, loops)
- ✅ Recursion vs Iteration
- ✅ C and C++ Interoperability

## 🚀 Getting Started

1. **Clone the Repository**
   ```bash
   git clone https://github.com/Pardeep-Kumar0/OOPS-Practical-Sem-5th.git
   cd OOPS-Practical-Sem-5th
   ```

2. **Navigate to an Experiment**
   ```bash
   cd OPPS-Practical-Sem-5th/exp1
   ```

3. **Compile and Run**
   ```bash
   g++ exp1-oop.cpp -o program
   ./program
   ```

4. **Experiment and Learn**
   - Read the comments in each source file
   - Modify the code to understand concepts better
   - Try creating your own variations

## 💡 Tips for Students

- **Read the Code Comments**: Each program has detailed comments explaining the concepts
- **Compile Warnings**: Use `-Wall` flag to see all warnings: `g++ -Wall filename.cpp`
- **Debug Mode**: Use `-g` flag for debugging: `g++ -g filename.cpp -o program`
- **Experiment**: Don't just run the code - modify it, break it, fix it. That's how you learn!
- **Memory Checks**: On Linux, use `valgrind` to check for memory leaks:
  ```bash
  valgrind --leak-check=full ./program
  ```

## 🤝 Contributing

If you find any issues or want to add improvements:

1. Fork the repository
2. Create a new branch (`git checkout -b feature/improvement`)
3. Make your changes
4. Commit your changes (`git commit -am 'Add some improvement'`)
5. Push to the branch (`git push origin feature/improvement`)
6. Create a Pull Request

## 📧 Contact

For any queries or discussions related to these practicals, please open an issue in the repository.

## 📄 License

This repository is for educational purposes. Feel free to use the code for learning and academic purposes.

---

**Happy Coding! 🎉**

*Remember: The best way to learn programming is by doing. Run these programs, understand them, modify them, and create your own variations!*


**Made with dedication by: Pardeep Kumar**
