#include <iostream>
#include <vector>
using namespace std;

// Function to find the greatest common divisor of two numbers
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    // Reading the array elements
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] /= 2; // Dividing the element by 2
    }

    long long lcd = 1; // Variable to store the least common multiple

    // Finding the least common multiple of all array elements
    for (int i = 0; i < n; i++) {
        long long g = gcd(lcd, a[i]);
        lcd = lcd * a[i] / g; // Updating the value of lcd

        // Checking if lcd is greater than m
        if (lcd > m) {
            cout << 0 << endl; // If true, print 0 and return
            return 0;
        }
    }

    // Checking if any array element is a factor of lcd
    for (int i = 0; i < n; i++) {
        if ((lcd / a[i]) % 2 == 0) { // Checking if the remainder of lcd divided by the current array element is 0 and even
            cout << 0 << endl; // If true, print 0 and return
            return 0;
        }
    }

    // Printing the result
    cout << (m / lcd + 1) / 2 << endl;
    return 0;
}

