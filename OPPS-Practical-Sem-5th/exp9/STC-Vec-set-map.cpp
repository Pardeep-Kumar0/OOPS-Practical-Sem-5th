// Experiment 9 — STL Basics (Vector, Set, Map & Algorithms)
// 1. Question (short)

// Write a C++ program that:

// Takes N integers from the user.

// Stores them in a vector<int>.

// Sorts and prints them using std::sort.

// Prints unique values using std::set.

// Counts frequency of each number using std::map<int,int>.

// Uses at least one STL algorithm like std::find or std::count.

// exp9.cpp
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm> // sort, find, count

using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v;
    v.reserve(n);

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // 1) sort
    sort(v.begin(), v.end());
    cout << "\nSorted: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // 2) unique values using set
    set<int> s(v.begin(), v.end());
    cout << "Unique values (set): ";
    for (int x : s) cout << x << " ";
    cout << "\n";

    // 3) frequency using map
    map<int,int> freq;
    for (int x : v) freq[x]++;
    cout << "Frequencies (map):\n";
    for (auto &p : freq) {
        cout << p.first << " -> " << p.second << "\n";
    }

    // 4) use algorithms: find & count
    int key;
    cout << "\nEnter a number to search: ";
    cin >> key;

    auto it = find(v.begin(), v.end(), key);
    if (it != v.end())
        cout << key << " found in vector\n";
    else
        cout << key << " not found in vector\n";

    cout << key << " appears " << count(v.begin(), v.end(), key)
         << " time(s) (using std::count)\n";

    return 0;
}


// Explanation (clear and simple)
// What is STL?

// STL (Standard Template Library) = ready-made C++ components:

// Containers → store data (vector, set, map, list, etc.)

// Algorithms → work on containers (sort, find, count, etc.)

// Iterators → like pointers that move over containers.

// Key Concepts in This Experiment

// vector<int>

// Dynamic array, grows automatically.

// v.push_back(x) adds elements.

// v.begin(), v.end() give iterators.

// std::sort (algorithm)

// Sorts any range [begin, end) in ascending order by default:

// sort(v.begin(), v.end());


// set<int> (ordered, unique)

// Stores unique keys in sorted order.

// Initializing from vector:

// set<int> s(v.begin(), v.end());


// map<int,int> for frequency

// Key → value mapping (here: number → its count).

// Automatically sorted by key.

// freq[x]++;   // creates key if missing, then increments


// std::find and std::count

// find(first, last, value) → iterator to value or end() if not found.

// count(first, last, value) → how many times value appears.

// Why this experiment is important

// You start to think in STL instead of manually writing loops for everything.

// These are core tools used in interviews and real-world C++: vector, set, map, sort, find, count.

// You learn to combine containers + algorithms for clean, short, powerful code.