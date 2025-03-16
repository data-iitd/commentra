#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the least common multiple of two numbers a and b.
long long lcm(long long a, long long b) {
    // Calculate the greatest common divisor of a and b using the gcd function.
    long long g = gcd(a, b);
    // Return the product of a and b divided by their greatest common divisor.
    return a * b / g;
}

// Function to calculate the greatest common divisor of two numbers a and b.
long long gcd(long long a, long long b) {
    // If b is 0, return a.
    if (b == 0) {
        return a;
    }
    // If a is 0, return b.
    if (a == 0) {
        return b;
    }
    // If a is greater than b, return the gcd of a and b - a.
    if (a > b) {
        return gcd(a, b - a);
    }
    // If b is greater than a, return the gcd of a and b - b.
    if (b > a) {
        return gcd(a, b - b);
    }
}

int main() {
    // Reading the input N and storing the list A of N integers.
    int N;
    cin >> N;
    long long A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Initializing the variable _lcm to 1.
    long long _lcm = 1;

    // Iterating through each number a in the list A and updating the value of _lcm using the lcm function.
    for (int i = 0; i < N; i++) {
        // Update the value of _lcm using the lcm function.
        _lcm = lcm(_lcm, A[i]);
    }

    // Calculating the answer ans using the formula _lcm * sum ( [ pow ( s , MOD - 2 , MOD ) for s in A ] ) % MOD.
    long long ans = _lcm * sum([pow(s, MOD - 2, MOD) for s in A]) % MOD;

    // Printing the final answer.
    cout << int(ans % MOD) << endl;

    return 0;
}

