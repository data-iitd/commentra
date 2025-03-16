
#include <iostream> // Importingiostream for input/output
#include <vector> // Importing vector for dynamic arrays
#include <algorithm> // Importing algorithm for sorting

using namespace std;

int main() {
    int mod = 1000000007; // Defining the modulo value
    int n; // Declaring variable n
    cin >> n; // Reading the first line and storing it in n
    vector<int> c(n); // Initializing a vector of size n to store the integers
    for (int i = 0; i < n; i++) {
        cin >> c[i]; // Reading each element and storing it in the vector c
    }

    if (n == 1) {
        cout << c[0] * 2 % mod << endl; // If n is 1, print the result directly
        return 0; // Exit the program as no further computation is needed
    }
    sort(c.begin(), c.end()); // Sorting the vector c in ascending order

    long long b = 1; // Initializing variable b
    for (int i = 0; i < n; i++) {
        b = b * 2 % mod; // Calculating 2^n
    }
    long long a = 1; // Initializing variable a
    for (int i = 0; i < n - 2; i++) {
        a = a * 2 % mod; // Calculating 2^(n-2)
    }
    long long ans = 0; // Initializing variable ans

    // Calculating the final answer
    for (int i = 2; i <= n + 1; i++) {
        long long val = a * i % mod; // Intermediate calculation
        val = val * c[n + 1 - i] % mod; // Intermediate calculation
        ans = (ans + val) % mod; // Adding to the answer
    }
    ans = ans * b % mod; // Multiplying the answer by b
    cout << ans << endl; // Printing the final result

    return 0; // End of the program
}

