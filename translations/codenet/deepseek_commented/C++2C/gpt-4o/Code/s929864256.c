#include <stdio.h> // For input and output
#include <stdlib.h> // For using the max function

typedef long long ll;

<<<<<<< HEAD
=======
const ll INF = 1LL<<60; // Define a constant for infinity
const ll MOD = 1000000007; // Define a constant for modulo operation

// Function to compute the maximum of three values
ll max(ll x, ll y, ll z) {
    if (x >= y && x >= z) return x;
    if (y >= x && y >= z) return y;
    return z;
}

>>>>>>> 98c87cb78a (data updated)
int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b); // Read two long long integers from standard input

    // Compute the maximum value among a+b, a-b, and a*b
<<<<<<< HEAD
    ll result = (a + b > a - b) ? (a + b > a * b ? a + b : a * b) : (a - b > a * b ? a - b : a * b);
    printf("%lld\n", result); // Print the maximum value
=======
    printf("%lld\n", max(a + b, a - b, a * b)); // Print the maximum value
>>>>>>> 98c87cb78a (data updated)

    return 0; // Return 0 indicating successful execution
}

// <END-OF-CODE>
