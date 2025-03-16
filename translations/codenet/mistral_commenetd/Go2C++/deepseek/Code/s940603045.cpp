#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Constants and variables declaration
const long long inf = numeric_limits<long long>::max(); // Constants for maximum signed integer value

// Global variables declaration

// ---------------------------------------------------------

// init function initializes the program
void init() {
    srand(time(NULL)); // Seed random number generator with current time
}

// main function is the entry point of the program
int main() {
    // Read input N as a string
    string N;
    cin >> N;
    // Convert N to an integer
    int n = 0;
    // Iterate through each digit in the number N
    for (char c : N) {
        n += c - '0'; // Convert each digit to an integer and add to the sum
    }
    // Read input m as an integer
    int m;
    m = stoi(N);
    // Check if m is divisible by n
    if (m % n == 0) {
        cout << "Yes" << endl; // Print "Yes" if m is divisible by n
    } else {
        cout << "No" << endl; // Print "No" if m is not divisible by n
    }
    return 0;
}

// ---------------------------------------------------------

// Pair type definition for storing two integers
struct Pair {
    int a, b;
};

// Pairs type definition for storing a vector of Pair
typedef vector<Pair> Pairs;

// Implement Len, Swap, and Less methods for sorting Pairs based on the second element
bool len(const Pair& p) {
    return p.b;
}
void swap(Pair& p1, Pair& p2) {
    Pair temp = p1;
    p1 = p2;
    p2 = temp;
}
bool less(const Pair& p1, const Pair& p2) {
    return p1.b < p2.b; // Sort based on the second element
}

// ------int methods-------------------------
bool in(int c, int a, int z) {
    return c >= a && c < z; // Check if c is within the range [a, z)
}
bool out(int c, int a, int z) {
    return !in(c, a, z); // Check if c is outside the range [a, z)
}
int btoi(bool b) {
    return b ? 1 : 0; // Convert boolean to integer: 1 for true, 0 for false
}
bool itob(int a) {
    return a != 0; // Convert integer to boolean: true for non-zero, false for zero
}
int max(int a, int b) {
    return a > b ? a : b; // Find the maximum integer among the given integers
}
int min(int a, int b) {
    return a < b ? a : b; // Find the minimum integer among the given integers
}
int sum(const vector<int>& a) {
    int r = 0;
    for (int i : a) {
        r += i; // Calculate the sum of all integers in the given slice
    }
    return r;
}
int pro(const vector<int>& a) {
    int r = a[0];
    for (int i = 1; i < a.size(); i++) {
        r *= a[i]; // Calculate the product of all integers in the given slice
    }
    return r;
}

vector<int> fill(vector<int>& a, int n) {
    for (int& i : a) {
        i = n; // Fill the given slice with the given integer value
    }
    return a;
}
pair<int, int> minmax(int a, int b) {
    return a < b ? make_pair(a, b) : make_pair(b, a); // Return the minimum and maximum integers among the given integers
}

int abs(int a) {
    return a < 0 ? -a : a; // Calculate the absolute value of an integer
}

// ---------- buffered scanner -----------------------------------------
class Scanner {
public:
    Scanner(istream& is) : r(is) {}

    string next() {
        string line;
        getline(r, line);
        return line;
    }

    int nextInt() {
        int value;
        r >> value;
        return value;
    }

    vector<int> nextInts(int n) {
        vector<int> values(n);
        for (int i = 0; i < n; i++) {
            r >> values[i];
        }
        return values;
    }

private:
    istream& r;
};

