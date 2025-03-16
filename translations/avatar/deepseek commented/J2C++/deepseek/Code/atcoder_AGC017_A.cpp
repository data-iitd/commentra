#include <iostream>
#include <vector>
#include <cmath>
#include <gmpxx.h>

using namespace std;

// Function to calculate combination (n choose m) using BigInteger for large numbers
mpz_class C(int n, int m) {
    mpz_class res = 1; // Initialize result to 1
    // Calculate product from m-n+1 to m
    for (int i = m - n + 1; i <= m; i++)
        res *= i;
    // Divide by product from 1 to n
    for (int i = 1; i <= n; i++)
        res /= i;
    return res;
}

int main() {
    int n, p;
    int k0 = 0; // Count of even numbers
    int k1 = 0; // Count of odd numbers

    // Read number of items (n) and the value of p
    cin >> n >> p;

    // Count even and odd numbers in the input
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 1)
            k1++;
        else
            k0++;
    }

    // Initialize result for number of ways to arrange items
    mpz_class ans = 1;

    // Calculate number of ways based on the value of p
    for (int i = 0; i < k0; i++)
        ans *= 2; // Multiply by 2 for each even number

    if (p == 0) {
        mpz_class add = 0;
        // Sum combinations of odd numbers, taking 0, 2, 4, ... odd numbers
        for (int i = 0; i <= k1; i += 2)
            add += C(i, k1);
        ans *= add; // Multiply result by the sum
        cout << ans << endl; // Print final result
    } else {
        mpz_class add = 0;
        // Sum combinations of odd numbers, taking 1, 3, 5, ... odd numbers
        for (int i = 1; i <= k1; i += 2)
            add += C(i, k1);
        ans *= add; // Multiply result by the sum
        cout << ans << endl; // Print final result
    }

