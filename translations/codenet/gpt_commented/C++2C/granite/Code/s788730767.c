
#include <stdio.h>
#include <math.h>

typedef long long ll;

// Function to calculate permutations nPr
ll nPr(ll n, ll r) {
    ll res = 1;
    // Calculate nPr using the formula n! / (n - r)!
    for (int i = 0; i < r; i++) {
        res *= (n - i); // Multiply by (n - i) for r times
    }
    return res; // Return the result
}

// Function to calculate combinations nCr
ll nCr(ll n, ll r) {
    // Using the formula nCr = nPr(n, r) / r!
    double res = 1;
    // Calculate nCr using an iterative approach to avoid large intermediate values
    for (int i = 0; i < r; i++) {
        res *= (n - i); // Multiply by (n - i)
        res /= (i + 1); // Divide by (i + 1) to account for r!
    }
    return (ll)res; // Return the result as long long
}

int main() {
    // Input the number of elements and the parity flag
    int n, p;
    scanf("%d %d", &n, &p);

    // Read the array elements and count even and odd numbers
    int a[n];
    int b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Input each element
        if (a[i] % 2 == 0) {
            b++; // Increment even count
        }
        else {
            c++; // Increment odd count
        }
    }

    // Initialize sums for combinations
    ll bsum = 0, csum = 0;
    // Calculate the total subsets of even numbers (2^b)
    bsum = (ll)pow(2, b);

    // Calculate combinations of odd numbers based on the parity flag
    if (p == 0) {
        // If p is 0, count combinations of even counts of odd numbers
        for (int i = 0; i <= c; i++) {
            if (i % 2 == 0) {
                csum += nCr(c, i); // Add combinations for even i
            }
        }
    }
    else {
        // If p is 1, count combinations of odd counts of odd numbers
        for (int i = 0; i <= c; i++) {
            if (i % 2 == 1) {
                csum += nCr(c, i); // Add combinations for odd i
            }
        }
    }

    // Calculate the final answer as the product of bsum and csum
    ll ans = bsum * csum;
    // Output the result
    printf("%lld\n", ans);
}

