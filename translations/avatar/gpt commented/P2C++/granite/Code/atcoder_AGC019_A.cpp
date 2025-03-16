
#include <bits/stdc++.h>
using namespace std;

// Define the gcd function based on C++ version
int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

// Define the ceil function to compute the ceiling of a divided by b
int ceil(int a, int b=1) {
    return (a + b - 1) / b;
}

// Define the round function to round a number to the nearest integer
int round(double x) {
    return (int)(x + 0.5);
}

// Define the fermat function to compute Fermat's little theorem for modular inverse
int fermat(int x, int y, int MOD) {
    return x * pow(y, MOD - 2, MOD) % MOD;
}

// Define the lcm function to compute the least common multiple of two numbers
int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

// Define the lcm_list function to compute the least common multiple of a list of numbers
int lcm_list(vector<int> nums) {
    int ans = 1;
    for (int num : nums) {
        ans = lcm(ans, num);
    }
    return ans;
}

// Define the INT function to read an integer from input
int INT() {
    int x;
    cin >> x;
    return x;
}

// Define the MAP function to read a list of integers from input
vector<int> MAP() {
    vector<int> v;
    int x;
    while (cin >> x) {
        v.push_back(x);
    }
    return v;
}

// Define the LIST function to read a list of integers into a list
vector<int> LIST(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    return v;
}

// Set the maximum recursion limit
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const double eps = 1e-8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Read input values for costs of different types of drinks
    int q, h, s, d;
    cin >> q >> h >> s >> d;

    // Read the number of drinks to be purchased
    int n;
    cin >> n;

    // Calculate the best price for 1 liter of drink
    int best1L = min({q * 4, h * 2, s});

    // Calculate the best price for 2 liters of drink
    int best2L = min(d, best1L * 2);

    // Calculate and print the total cost based on whether n is even or odd
    if (n % 2 == 0) {
        cout << best2L * (n / 2) << endl;  // Total cost for even number of drinks
    } else {
        cout << best2L * (n / 2) + best1L << endl;  // Total cost for odd number of drinks
    }

    return 0;
}

Translate the above C++ code to Java and end with comment "