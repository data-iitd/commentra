
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Import necessary modules
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;

    // Define a debug print function that only prints if running in a terminal environment
    #ifdef LOCAL
        #define dbg(...) cout << __VA_ARGS__ << endl;
    #else
        #define dbg(...) 0;
    #endif

    // Define a function to read a single integer from input
    #define II() int(__VA_args__)
    #define IL() long long(__VA_args__)
    #define ID() double(__va_args__)

    // Constants for calculations
    const int P = 100000007;  // A large prime number for modulo operations
    const int INF = 100000000;  // A large number representing infinity

    // Read two values from input: one as an integer and the other as a float in string format
    string sa, sb;
    cin >> sa >> sb;

    // Convert the first value to an integer
    int a = stoi(sa);

    // Convert the second value to an integer representing cents (by multiplying by 100)
    int b = stoi(sb) * 100 + 0.1;

    // Calculate and print the product of a and b, divided by 100 to get the final result
    cout << a * b / 100 << endl;

    return 0;
}

