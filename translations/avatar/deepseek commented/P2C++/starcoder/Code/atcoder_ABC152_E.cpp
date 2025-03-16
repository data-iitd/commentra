#include <bits/stdc++.h>
using namespace std;

// Define a function to calculate the least common multiple (LCM) of two numbers
long long lcm(long long a, long long b) {
    return a * b / __gcd(a, b);  // Using the gcd function to calculate the LCM
}

const long long MOD = 1e9 + 7;  // Define a constant MOD for modulo operations

int main() {
    int N;  // Read the number of elements in the list A
    cin >> N;
    vector<int> A(N);  // Read the list A as integers split by spaces
    for (int i = 0; i < N; i++) cin >> A[i];

    long long _lcm = 1;  // Initialize _lcm to 1
    for (int a : A) {
        _lcm = _lcm * a / __gcd(_lcm, a);  // Update _lcm to be the LCM of _lcm and the current element
    }

    // Calculate ans as _lcm multiplied by the sum of modular inverses of each element in A modulo MOD
    long long ans = _lcm * accumulate(A.begin(), A.end(), 0, [](long long a, long long b) {
        return (a + b) % MOD;
    }) % MOD;

    cout << ans << endl;  // Print the result, ensuring it is within the modulo range

    return 0;
}

