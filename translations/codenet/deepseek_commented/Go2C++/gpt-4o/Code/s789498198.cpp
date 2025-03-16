#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>

using namespace std;

// Function to read integers from input
vector<int> nextInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> result;
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

// Main function of the program
int main() {
    // Read two integers A and B from standard input
    vector<int> AB = nextInts();
    int A = AB[0];
    int B = AB[1];

    // Check if the sum of A and B is even
    if ((A + B) % 2 == 0) {
        // If even, print the average of A and B
        cout << (A + B) / 2 << endl;
        return 0;
    }
    // If not even, print "IMPOSSIBLE"
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

// Utility functions
int digits(int x) {
    return to_string(x).length();
}

int powInt(int x, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= x;
    }
    return result;
}

int max(int x, int y) {
    return std::max(x, y);
}

int min(int x, int y) {
    return std::min(x, y);
}

int abs(int x) {
    return std::abs(x);
}

void varDump(const vector<int>& values) {
    for (const auto& v : values) {
        cerr << v << endl;
    }
}

void yes() {
    cout << "Yes" << endl;
}

void no() {
    cout << "No" << endl;
}

// Pair struct to hold two integers
struct Pair {
    int first;
    int second;
};

// Queue struct to hold a vector of Pairs
class Queue {
public:
    vector<Pair> v;

    void Push(Pair p) {
        v.push_back(p);
    }

    Pair Pop() {
        Pair r = v.front();
        v.erase(v.begin());
        return r;
    }

    Pair Front() {
        return v.front();
    }

    bool Empty() {
        return v.empty();
    }
};

// <END-OF-CODE>
