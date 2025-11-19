/*Problem (restated)

Write a Student Grading mini-app that:

Reads N students: id (int), name (string), marks in 3 subjects (integers).

Computes total and grade for each student. Grade rules (example):

total >= 270 → A

total >= 210 → B

total >= 150 → C

otherwise F

Prints a sorted report by total descending (highest first).

Implement this in two ways:

Part A: Procedure-oriented (use struct + free functions + dynamic array).

Part B: Object-oriented (encapsulate data/behavior in classes).
*/


// procedural.cpp
#include <bits/stdc++.h>
using namespace std;

struct Student {
    int id;
    string name;
    int marks[3];
    int total;
    char grade;
};

void readStudents(Student* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].id >> ws;
        getline(cin, arr[i].name); // read full line name
        for (int j = 0; j < 3; ++j) cin >> arr[i].marks[j];
    }
}

void computeTotalsAndGrades(Student* arr, int n) {
    for (int i = 0; i < n; ++i) {
        int tot = 0;
        for (int j = 0; j < 3; ++j) tot += arr[i].marks[j];
        arr[i].total = tot;
        if (tot >= 270) arr[i].grade = 'A';
        else if (tot >= 210) arr[i].grade = 'B';
        else if (tot >= 150) arr[i].grade = 'C';
        else arr[i].grade = 'F';
    }
}

void printReport(Student* arr, int n) {
    cout << "ID\tName\tMarks(1,2,3)\tTotal\tGrade\n";
    cout << "-------------------------------------------------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i].id << '\t' 
             << arr[i].name << '\t';
        cout << arr[i].marks[0] << ',' << arr[i].marks[1] << ',' << arr[i].marks[2] << '\t';
        cout << arr[i].total << '\t' << arr[i].grade << '\n';
    }
}

int main() {
 

    int n;
    cout << "Enter number of students: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid N\n";
        return 1;
    }

    // allocate dynamic array (manual memory management)
    Student* arr = new Student[n];

    cout << "Enter student data (id then name line then 3 marks):\n";
    readStudents(arr, n);

    computeTotalsAndGrades(arr, n);

    // sort by total descending using std::sort and lambda (still procedural)
    sort(arr, arr + n, [](const Student &a, const Student &b){
        return a.total > b.total;
    });

    printReport(arr, n);

    delete[] arr; // clean up
    return 0;
}
