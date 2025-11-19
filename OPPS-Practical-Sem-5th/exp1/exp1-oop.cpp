// oop.cpp
#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    int id;
    string name;
    array<int,3> marks;
    int total;
    char grade;

    void computeTotalAndGrade() {
        total = marks[0] + marks[1] + marks[2];
        if (total >= 270) grade = 'A';
        else if (total >= 210) grade = 'B';
        else if (total >= 150) grade = 'C';
        else grade = 'F';
    }

public:
    Student() : id(0), name(""), marks{0,0,0}, total(0), grade('F') {}
    Student(int id_, const string &name_, const array<int,3> &marks_)
        : id(id_), name(name_), marks(marks_) {
        computeTotalAndGrade();
    }

    // getters (const)
    int getId() const { return id; }
    string getName() const { return name; }
    int getTotal() const { return total; }
    char getGrade() const { return grade; }
    array<int,3> getMarks() const { return marks; }

    // update marks and recompute
    void setMarks(const array<int,3> &m) {
        marks = m;
        computeTotalAndGrade();
    }

    // print self
    void print() const {
        cout << id << '\t' << name << '\t'
             << marks[0] << ',' << marks[1] << ',' << marks[2] << '\t'
             << total << '\t' << grade << '\n';
    }
};

class StudentRepository {
private:
    vector<Student> students;

public:
    void add(const Student &s) { students.push_back(s); }

    void readFromStdin(int n) {
        string line;
        for (int i = 0; i < n; ++i) {
            int id;
            string name;
            array<int,3> m;
            cin >> id; 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            cin >> m[0] >> m[1] >> m[2];
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            students.emplace_back(id, name, m);
        }
    }

    void sortByTotalDesc() {
        sort(students.begin(), students.end(), [](const Student &a, const Student &b){
            return a.getTotal() > b.getTotal();
        });
    }

    void printReport() const {
        cout << "ID\tName\tMarks(1,2,3)\tTotal\tGrade\n";
        cout << "-------------------------------------------------------------\n";
        for (const auto &s : students) s.print();
    }
};

int main() {
  

    int n;
    cout << "Enter number of students: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid N\n";
        return 1;
    }

    StudentRepository repo;
    cout << "Enter student data (id then name line then 3 marks):\n";
    repo.readFromStdin(n);
    repo.sortByTotalDesc();
    repo.printReport();

    return 0;
}
