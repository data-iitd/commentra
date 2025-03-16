#include <iostream>
#include <algorithm>
using namespace std;

// Constants for infinity and modulo operations.
const long long inf = 1e20;
const int mod = 1e9 + 7;

// Function to read a list of integers from standard input.
void readInput(long long &a, long long &b, long long &c, long long &d) {
    cin >> a >> b >> c >> d;
}

int main() {
    long long a, b, c, d;
    readInput(a, b, c, d);
    // Calculating and returning the maximum of four possible products of two of the given numbers.
    cout << max({a * c, b * d, a * d, b * c}) << endl;
    return 0;
}

// <END-OF-CODE>
