#include <iostream>
#include <vector>
using namespace std;

// Function to compute the greatest common divisor (GCD) of two numbers
long long getGCD(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return getGCD(b, a % b);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    // Initialize array a with size n, where each element is half of the next input
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] /= 2;
    }

    long long gcd;
    long long lcd = 1;

    // Calculate the least common multiple (LCM) of the elements in array a
    for (int i = 0; i < n; i++) {
        gcd = getGCD(lcd, a[i]);
        lcd = lcd * a[i] / gcd;
        if (lcd > m) { // Check if LCM exceeds m
            cout << 0 << endl;
            return 0;
        }
    }

    // Check if the LCM is even for any element in the array
    for (int i = 0; i < n; i++) {
        if ((lcd / a[i]) % 2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    // Calculate and print the number of integers up to m that are divisible by the LCM
    cout << (m / lcd + 1) / 2 << endl;

    return 0;
}

