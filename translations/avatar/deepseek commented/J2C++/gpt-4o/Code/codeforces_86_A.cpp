#include <iostream>
#include <algorithm>

using namespace std;

// Function to calculate the number of digits in a given long integer
int power(long long a) {
    int res = 0;
    while (a > 0) {
        res++;
        a = a / 10;
    }
    return res;
}

// Function to calculate the maximum product of two numbers formed by splitting the given number into two parts
long long mult(long long a) {
    int pow = power(a);
    long long max = 0;
    for (int j = 0; j < pow; ++j) {
        max = max * 10 + 9;
    }
    return a * (max - a);
}

int main() {
    // Read two long integers from the input
    long long l, r;
    cin >> l >> r;
    long long res = 0;
    long long maxxes[10];
    long long temp = 0;

    // Calculate the maximum product for each range and store it in the array maxxes
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9;
        maxxes[i] = (temp / 2) * (temp - temp / 2);
    }

    // Calculate the maximum product for the given ranges and update the result res
    res = max(mult(l), res);
    res = max(mult(r), res);
    temp = 0;

    // Check if the middle value of the range is within the given range and update the result res accordingly
    for (int i = 0; i < 10; ++i) {
        temp = temp * 10 + 9;
        if (l <= temp / 2 && temp / 2 <= r) {
            res = max(maxxes[i], res);
        }
    }

    // Print the final result
    cout << res << endl;

    return 0;
}

// <END-OF-CODE>
