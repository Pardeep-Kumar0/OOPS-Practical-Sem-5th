// Experiment 10 — Student Database (short)

// Question (brief):
// Implement a small StudentDB supporting: add, delete (by id), edit (by id), search (by id/name), sort (by id/name/cgpa), save to file and load from file.

// student_db.cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

struct Student {
    int id;
    std::string name;
    double cgpa;

    std::string serialize() const {
        std::ostringstream o;
        o << id << '|' << name << '|' << cgpa;
        return o.str();
    }
    static Student deserialize(const std::string &line) {
        Student s{};
        std::istringstream in(line);
        std::string token;
        std::getline(in, token, '|'); s.id = std::stoi(token);
        std::getline(in, s.name, '|');
        std::getline(in, token); s.cgpa = std::stod(token);
        return s;
    }
    void print() const {
        std::cout << std::setw(4) << id << " | " << std::setw(15) << name
                  << " | " << std::fixed << std::setprecision(2) << cgpa << '\n';
    }
};

struct StudentDB {
    std::vector<Student> students;

    void add(const Student &s){ students.push_back(s); }
    bool removeById(int id){
        auto it = std::find_if(students.begin(), students.end(), [&](auto &x){ return x.id==id; });
        if (it==students.end()) return false;
        students.erase(it); return true;
    }
    Student* findById(int id){
        auto it = std::find_if(students.begin(), students.end(), [&](auto &x){ return x.id==id; });
        return it==students.end()? nullptr : &*it;
    }
    std::vector<Student*> findByName(const std::string &name){
        std::vector<Student*> out;
        for (auto &s: students) if (s.name==name) out.push_back(&s);
        return out;
    }
    void sortById(){ std::sort(students.begin(), students.end(), [](auto &a, auto &b){ return a.id < b.id; });}
    void sortByName(){ std::sort(students.begin(), students.end(), [](auto &a, auto &b){ return a.name < b.name; });}
    void sortByCgpaDesc(){ std::sort(students.begin(), students.end(), [](auto &a, auto &b){ return a.cgpa > b.cgpa; });}

    bool save(const std::string &file){
        std::ofstream out(file);
        if(!out) return false;
        for (auto &s: students) out << s.serialize() << '\n';
        return true;
    }
    bool load(const std::string &file){
        std::ifstream in(file);
        if(!in) return false;
        students.clear();
        std::string line;
        while (std::getline(in, line)) if(!line.empty()) students.push_back(Student::deserialize(line));
        return true;
    }
    void printAll() const {
        std::cout << " ID  | Name            | CGPA\n";
        std::cout << "-------------------------------\n";
        for (auto &s: students) s.print();
    }
};

int main(){
    StudentDB db;
    // quick demo: load file if exists
    db.load("students.txt");

    // demo usage (replace with interactive menu in full version)
    db.add({101,"Alice",8.6});
    db.add({102,"Ansh",9.9});
    db.add({103,"Mohinder",9.0});

    std::cout << "All students:\n"; db.printAll();

    std::cout << "\nSort by CGPA descending:\n";
    db.sortByCgpaDesc(); db.printAll();

    std::cout << "\nSearch id=102:\n";
    if (auto s = db.findById(102)) s->print(); else std::cout << "Not found\n";

    std::cout << "\nRemove id=101 -> ";
    std::cout << (db.removeById(101) ? "removed\n" : "not found\n");
    db.printAll();

    std::cout << "\nSave DB to students.txt\n";
    if (!db.save("students.txt")) std::cerr << "Save failed\n";

    return 0;
}

// Explanation — key points (short & focused)

// Design: Student holds data and knows how to serialize()/deserialize() to a simple id|name|cgpa text line. StudentDB manages a std::vector<Student> and provides add/remove/search/sort.

// Search: std::find_if returns first match; findByName returns all matches (could be multiple).

// Sort: std::sort with lambdas — sortByCgpaDesc shows sorting by a different criterion.

// Persistence: save() writes lines; load() reads and rebuilds students. Simple text format is human-readable and easy to debug.

// Extensibility: To support UG/PG specialization, replace Student with a base class and store std::vector<std::unique_ptr<Student>> so you can use polymorphism (override print/serialize).

// Robustness: This short example omits heavy input validation — production code should validate file contents, handle parsing errors, and use transactions/temporary files for safe saving.