// Including necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining constants and macros
#define ll long long
#define N 200010

// Function prototypes
ll read();
void write(ll x);
void writeln(ll x);

// Global variables
ll a[N], q[N], n, tot;

// Main function
int main() {
    // Reading input
    n = read();

    // Reading array 'a'
    for (ll i = 1; i <= n; ++i) {
        a[i] = read();
    }

    // Sorting array 'a' in ascending order
    qsort(a + 1, n, sizeof(ll), cmpfunc);

    // Finding duplicate elements and storing them in 'q'
    for (ll i = 1; i <= n; ++i) {
        if (a[i] == a[i + 1]) { // Checking if current element is same as next element
            q[++tot] = a[i];    // If yes, storing it in 'q'
            i++;                // Incrementing index 'i'
        }
    }

    // Outputting the result
    writeln(q[tot] * q[tot - 1]);

    // End of main function
    return 0;
}

// Function to read input
ll read() {
    ll x;
    scanf("%lld", &x);
    return x;
}

// Function to write output
void write(ll x) {
    printf("%lld", x);
}

// Function to write output with newline
void writeln(ll x) {
    printf("%lld\n", x);
}

// Comparison function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(ll*)a - *(ll*)b);
}
