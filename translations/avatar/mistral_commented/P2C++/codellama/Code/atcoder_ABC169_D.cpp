#include <bits/stdc++.h>
using namespace std;

// Define constants
const int INF = 999999999999999999999999;
const int MOD = 1000000007;

// Function to prime factorize a number
vector<int> prime_factorize(int n) {
    vector<int> a;
    while (n % 2 == 0) {
        a.push_back(2);
        n /= 2;
    }
    int f = 3;
    while (f * f <= n) {
        if (n % f == 0) {
            a.push_back(f);
            n /= f;
        } else {
            f += 2;
        }
    }
    if (n != 1) {
        a.push_back(n);
    }
    return a;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate the sum of all integers i such that i > 1 and i is a multiple of p^e
int sum_of_multiples(int p, int e) {
    int x = e;
    int ans = 0;
    for (int i = 1; i <= 1000000000; i++) {
        if (x >= i) {
            x -= i;
            ans += 1;
        } else {
            break;
        }
    }
    return ans;
}

// Main function
int main() {
    // Get the number of test cases
    int n;
    cin >> n;

    // Base case for the recursion
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Prime factorize the number
    vector<int> fac_ = prime_factorize(n);
    map<int, int> fac;
    for (int i = 0; i < fac_.size(); i++) {
        fac[fac_[i]]++;
    }

    // Calculate the answer
    int ans = 0;
    for (auto it = fac.begin(); it != fac.end(); it++) {
        ans += sum_of_multiples(it->first, it->second);
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

