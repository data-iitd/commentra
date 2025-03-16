#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>

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

// Main function
int main() {
    // Read the first two integers from the input
    vector<int> AB = nextInts();
    int A = AB[0];
    int B = AB[1];

    // Check if the sum of A and B is even
    if ((A + B) % 2 == 0) {
        // If it is, print the result (the average)
        cout << (A + B) / 2 << endl;
    } else {
        // If the sum is odd, print "IMPOSSIBLE"
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

// Function to calculate the number of digits in an integer
int digits(int x) {
    return to_string(x).length();
}

// Function to calculate the power of a number
int powInt(int x, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= x;
    }
    return result;
}

// Function to find the maximum of two integers
int max(int x, int y) {
    return std::max(x, y);
}

// Function to find the minimum of two integers
int min(int x, int y) {
    return std::min(x, y);
}

// Function to calculate the absolute value of an integer
int abs(int x) {
    return std::abs(x);
}

// Function to print "Yes"
void yes() {
    cout << "Yes" << endl;
}

// Function to print "No"
void no() {
    cout << "No" << endl;
}

// Pair type definition
struct Pair {
    int first;
    int second;
};

// Queue type definition
class Queue {
public:
    vector<Pair> v;

    // Function to push a pair into the queue
    void Push(Pair p) {
        v.push_back(p);
    }

    // Function to pop a pair from the queue
    Pair Pop() {
        Pair r = v[0];
        v.erase(v.begin());
        return r;
    }

    // Function to get the front pair from the queue
    Pair Front() {
        return v[0];
    }

    // Function to check if the queue is empty
    bool Empty() {
        return v.empty();
    }
}

// <END-OF-CODE>
