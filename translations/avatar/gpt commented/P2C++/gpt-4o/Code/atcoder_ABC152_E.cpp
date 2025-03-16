#include <iostream>
#include <vector>
#include <numeric> // For std::gcd
using namespace std;

const int MOD = 1e9 + 7; // Define a constant MOD for modular arithmetic

long long lcm(long long a, long long b) {
    return a * (b / gcd(a, b)); // Calculate the least common multiple (LCM)
}

int main() {
    int N; // Number of elements
    cin >> N; // Read the number of elements from user input
    vector<int> A(N); // Vector to store the elements
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read the list of integers from user input
    }

    long long _lcm = 1; // Initialize the variable to store the LCM of the list
    for (int a : A) {
        _lcm = lcm(_lcm, a); // Update the LCM
    }

    // Calculate the final answer using the LCM and the modular inverses of the elements in A
    long long ans = _lcm; // Start with the LCM
    for (int s : A) {
        ans = (ans + (pow(s, MOD - 2) % MOD)) % MOD; // Add modular inverses
    }

    // Print the result, ensuring it is within the bounds of MOD
    cout << ans % MOD << endl;

    return 0;
}

// <END-OF-CODE>
