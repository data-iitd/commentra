
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to calculate the least common multiple of two numbers a and b.
long long lcm(long long a, long long b) {
    // Calculate the greatest common divisor of a and b using the __gcd function.
    long long g = __gcd(a, b);
    // Return the product of a and b divided by their greatest common divisor.
    return a * b / g;
}

int main() {
    // Set the value of MOD to 10^9 + 7.
    const long long MOD = 100000007;

    // Read the input N and store the vector A of N integers.
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Initialize the variable _lcm to 1.
    long long _lcm = 1;

    // Iterate through each number a in the vector A and update the value of _lcm using the lcm function.
    for (int i = 0; i < N; i++) {
        _lcm = lcm(_lcm, A[i]);
    }

    // Calculate the answer ans using the formula _lcm * sum ( [ pow ( s, MOD - 2, MOD ) for s in A ] ) % MOD.
    long long ans = _lcm * accumulate(A.begin(), A.end(), 0, [=](long long a, long long b) {
        return (a + pow(b, MOD - 2, MOD)) % MOD;
    }) % MOD;

    // Print the final answer.
    cout << ans << endl;

    return 0;
}

