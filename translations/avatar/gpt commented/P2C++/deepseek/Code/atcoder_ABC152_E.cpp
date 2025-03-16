#include <iostream>
#include <vector>
#include <numeric>  // For std::gcd

using namespace std;

const long long MOD = 1000000007;

long long lcm(long long a, long long b) {
    // Calculate the least common multiple (LCM) of two numbers a and b
    return a / gcd(a, b) * b;
}

int main() {
    int N;
    cin >> N;  // Read the number of elements from user input
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];  // Read a list of integers from user input
    }

    long long _lcm = 1;  // Initialize the variable to store the LCM of the list
    for (long long a : A) {
        // Update the LCM by calculating the LCM of the current LCM and the next element
        _lcm = lcm(_lcm, a);
    }

    // Calculate the final answer using the LCM and the modular inverses of the elements in A
    long long ans = _lcm * accumulate(A.begin(), A.end(), 0LL, [](long long sum, long long s) {
        return (sum + pow(s, MOD - 2, MOD)) % MOD;
    }) % MOD;

    // Print the result, ensuring it is within the bounds of MOD
    cout << ans << endl;

    return 0;
}
