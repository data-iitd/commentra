#include <iostream> // Including iostream for input and output
#include <vector> // Including vector for dynamic array
#include <algorithm> // Including algorithm for sorting
#include <sstream> // Including sstream for string stream
using namespace std;

// Function to calculate x^n % mod
long long power(long long x, long long n, int mod) {
    if (n == 0) {
        return 1; // Base case: x^0 is 1
    }
    long long val = power(x, n / 2, mod); // Recursive call to calculate x^(n/2)
    val = val * val % mod; // Squaring the result
    if (n % 2 == 1) {
        val = val * x % mod; // Multiplying by x if n is odd
    }
    return val; // Returning the result
}

int main() {
    ios::sync_with_stdio(false); // For faster input/output
    cin.tie(nullptr); // Untie cin from cout

    int mod = 1000000007; // Defining the modulo value
    int n;
    cin >> n; // Reading the size of the array
    vector<int> c(n); // Initializing a vector of size n to store the integers
    for (int i = 0; i < n; i++) {
        cin >> c[i]; // Reading each element into the vector c
    }

    if (n == 1) {
        cout << (c[0] * 2LL % mod) << endl; // If n is 1, print the result directly
        return 0; // Exit the program as no further computation is needed
    }

    sort(c.begin(), c.end()); // Sorting the vector c in ascending order

    long long b = power(2, n, mod); // Calculating 2^n
    long long a = power(2, n - 2, mod); // Calculating 2^(n-2)
    long long ans = 0; // Initializing the answer variable

    // Calculating the final answer
    for (int i = 2; i <= n + 1; i++) {
        long long val = a * i % mod; // Intermediate calculation
        val = val * c[n + 1 - i] % mod; // Intermediate calculation
        ans = (ans + val) % mod; // Adding to the answer
    }
    ans = ans * b % mod; // Multiplying the answer by b
    cout << ans << endl; // Printing the final result

    return 0; // Indicating successful completion
}

// <END-OF-CODE>
