#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// FastScanner class: Efficiently reads input.
class FastScanner {
public:
    FastScanner() : buffer("") {}

    // Reads the next integer from the input.
    int NextInt() {
        int value;
        string token;
        getline(cin, buffer);
        stringstream ss(buffer);
        ss >> token;
        value = stoi(token);
        return value;
    }

private:
    string buffer;
};

// Main function: Entry point of the program.
int main() {
    FastScanner fsc;
    int A = fsc.NextInt();
    int B = fsc.NextInt();
    int C = fsc.NextInt();
    
    if (B - A == C - B) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

// Utility functions for various operations.
int IntMax(int a, int b) {
    return (a < b) ? b : a;
}

int IntMin(int a, int b) {
    return (a > b) ? b : a;
}

int IntGcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return IntGcd(b, a % b);
}

int IntAbs(int a) {
    return (a < 0) ? -a : a;
}

