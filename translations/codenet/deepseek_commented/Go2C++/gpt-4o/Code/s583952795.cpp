#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

string i2s(int i) {
    return to_string(i);
}

int TenToN(int number, int n) {
    string s;
    int tmp = number;
    do {
        s = i2s(tmp % n) + s;
        tmp /= n;
    } while (tmp >= n);
    return s.length();
}

int main() {
    int N, K;
    cin >> N >> K;

    // Convert N to base K and print the length of the resulting string
    cout << TenToN(N, K) << endl;

    return 0;
}

// Utility functions can be added here if needed

// <END-OF-CODE>
