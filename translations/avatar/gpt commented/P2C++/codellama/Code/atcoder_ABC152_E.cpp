#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    // Calculate the greatest common divisor (GCD) of two numbers a and b
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    // Calculate the least common multiple (LCM) of two numbers a and b
    return a / gcd(a, b) * b;
}

const int MOD = 1e9 + 7;  // Define a constant MOD for modular arithmetic
int N;  // Define a variable to store the number of elements
int A[100000];  // Define an array to store the list of integers

int main() {
    // Read the number of elements from user input
    cin >> N;

    // Read a list of integers from user input
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int _lcm = 1;  // Initialize the variable to store the LCM of the list
    for (int i = 0; i < N; i++) {
        // Update the LCM by calculating the LCM of the current LCM and the next element
        _lcm = lcm(_lcm, A[i]);
    }

    // Calculate the final answer using the LCM and the modular inverses of the elements in A
    int ans = _lcm * (pow(A[0], MOD - 2) % MOD);
    for (int i = 1; i < N; i++) {
        ans = (ans + _lcm * (pow(A[i], MOD - 2) % MOD)) % MOD;
    }

    // Print the result, ensuring it is within the bounds of MOD
    cout << ans << endl;

    return 0;
}

