#include <iostream>
#include <vector>
#include <numeric> // for std::gcd

using namespace std;

// Function to calculate the least common multiple of two numbers a and b.
int lcm(int a, int b) {
    // Calculate the greatest common divisor of a and b using the gcd function.
    int g = gcd(a, b);
    // Return the product of a and b divided by their greatest common divisor.
    return a * b / g;
}

// Setting the value of MOD to 10^9 + 7.
const int MOD = 1000000007;

int main() {
    // Reading the input N and storing the list A of N integers.
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Initializing the variable _lcm to 1.
    int _lcm = 1;

    // Iterating through each number a in the list A and updating the value of _lcm using the lcm function.
    for (int a : A) {
        // Update the value of _lcm using the lcm function.
        _lcm = lcm(_lcm, a);
    }

    // Calculating the answer ans using the formula _lcm * sum ( [ pow ( s , MOD - 2 , MOD ) for s in A ] ) % MOD.
    long long ans = 0;
    long long sum = 0;
    for (int s : A) {
        sum += pow(s, MOD - 2, MOD);
    }
    ans = _lcm * sum % MOD;

    // Printing the final answer.
    cout << ans % MOD << endl;

    return 0;
}
