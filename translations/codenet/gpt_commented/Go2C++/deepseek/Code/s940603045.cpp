#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

// Direction vectors for 8 possible movements (up, down, left, right, and diagonals)
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

// Define an infinite value for comparison
const int inf = numeric_limits<int>::max();

// Initialize a new scanner for input
istream& next = cin;

// ---------------------------------------------------------
// init function to set up logging and random seed
void init() {
    ios::sync_with_stdio(false); // Disable synchronization with C I/O
    cin.tie(nullptr); // Untie input and output streams
    srand(time(nullptr)); // Seed the random number generator
}

// main function where the program execution starts
int main() {
    // Read input as a string
    string N;
    next >> N;
    vector<char> b(N.begin(), N.end()); // Convert string to vector of characters
    int n = 0; // Initialize sum of digits

    // Calculate the sum of digits in the input number
    for (char c : b) {
        n += c - '0'; // Convert char to int and accumulate
    }

    // Convert the string input to an integer
    int m = stoi(N);
    // Check if the number is divisible by the sum of its digits
    if (m % n == 0) {
        cout << "Yes" << endl; // Print "Yes" if divisible
    } else {
        cout << "No" << endl; // Print "No" if not divisible
    }

    return 0;
}

// ---------------------------------------------------------

// Pair struct to hold a pair of integers
struct Pair {
    int a, b;
};

// Pairs is a vector of Pair structs
typedef vector<Pair> Pairs;

// Implement Len method for sorting
int len(const Pairs& p) {
    return p.size();
}

// Implement Swap method for sorting
void swap(Pairs& p, int i, int j) {
    swap(p[i].a, p[j].a);
    swap(p[i].b, p[j].b);
}

// Implement Less method for sorting based on the second element of the Pair
bool less(const Pair& p1, const Pair& p2) {
    return p1.b < p2.b;
}

// Utility functions for various operations

// Check if a value is within a range
bool in(int c, int a, int z) {
    return c >= a && c < z;
}

// Check if a value is outside a range
bool out(int c, int a, int z) {
    return !in(c, a, z);
}

// Convert boolean to integer (1 for true, 0 for false)
int btoi(bool b) {
    return b ? 1 : 0;
}

// Convert integer to boolean (non-zero to true, zero to false)
bool itob(int a) {
    return a != 0;
}

// Return the maximum value from a list of integers
int max(int a, int b) {
    return a > b ? a : b;
}

// Return the minimum value from a list of integers
int min(int a, int b) {
    return a < b ? a : b;
}

// Calculate the sum of a vector of integers
int sum(const vector<int>& a) {
    int r = 0;
    for (int i : a) {
        r += i;
    }
    return r;
}

// Calculate the product of a vector of integers
int pro(const vector<int>& a) {
    int r = a[0];
    for (int i = 1; i < a.size(); i++) {
        r *= a[i];
    }
    return r;
}

// Fill a vector with a specified value
vector<int> fill(int n, int size) {
    vector<int> a(size, n);
    return a;
}

// Return the minimum and maximum of two integers
pair<int, int> minmax(int a, int b) {
    return a > b ? make_pair(b, a) : make_pair(a, b);
}

// Return the absolute value of an integer
int abs(int a) {
    return a < 0 ? -a : a;
}

// Calculate the ceiling of a division of two integers
int ceil(int a, int b) {
    return a % b != 0 ? 1 : 0;
}

// Print a vector of strings with space separation
void printStrings(const vector<string>& out) {
    for (int i = 0; i < out.size(); i++) {
        cout << out[i];
        if (i != out.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

// Print a vector of integers with space separation
void printInts(const vector<int>& out) {
    for (int i = 0; i < out.size(); i++) {
        cout << out[i];
        if (i != out.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

// ---------- buffered scanner -----------------------------------------

// Scanner class for buffered input reading
class Scanner {
public:
    Scanner() : buf(nullptr), p(0) {}

    // Read the next token from the input
    string next() {
        pre();
        int start = p;
        while (p < buf.size() && buf[p] != ' ') {
            p++;
        }
        string result = string(buf.begin() + start, buf.begin() + p);
        p++; // Move past the space
        return result;
    }

    // Read the entire line from the input
    string line() {
        pre();
        int start = p;
        while (p < buf.size() && buf[p] != '\n') {
            p++;
        }
        string result = string(buf.begin() + start, buf.begin() + p);
        p++; // Move past the newline
        return result;
    }

    // Read the next string from the input
    string string() {
        return next();
    }

    // Read the next integer from the input
    int int() {
        int v;
        cin >> v;
        return v;
    }

    // Read multiple integers from the input
    vector<int> ints(int n) {
        vector<int> r(n);
        for (int i = 0; i < n; i++) {
            r[i] = int();
        }
        return r;
    }

    // Read the next int64 from the input
    int64_t int64() {
        int64_t v;
        cin >> v;
        return v;
    }

    // Read the next uint64 from the input
    uint64_t uint64() {
        uint64_t v;
        cin >> v;
        return v;
    }

    // Read the next float64 from the input
    double float64() {
        double v;
        cin >> v;
        return v;
    }

private:
    vector<char> buf;
    int p;

    // Pre-read to ensure there is data in the buffer
    void pre() {
        if (p >= buf.size()) {
            string s;
            getline(cin, s);
            buf.assign(s.begin(), s.end());
            p = 0;
        }
    }
};

Scanner scanner;

