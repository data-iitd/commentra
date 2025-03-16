#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Function to read an integer from standard input.
int readInt() {
    int x;
    cin >> x;
    return x;
}

// The main function is the entry point of the program.
int main() {
    int K = readInt();

    // Check if K is divisible by 2 or 5, return -1 if true.
    if (K % 2 == 0 || K % 5 == 0) {
        cout << -1 << endl;
        return 0;
    }

    // If K is divisible by 7, divide K by 7.
    if (K % 7 == 0) {
        K /= 7;
    }

    // Multiply K by 9.
    K *= 9;

    // Initialize the answer and the remainder.
    int ans = 1;
    int remainder = 10 % K;

    // Loop to find the number of digits required to form a number that is a multiple of K.
    while (remainder != 1) {
        ans++;
        remainder = remainder * 10 % K;
    }

    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
