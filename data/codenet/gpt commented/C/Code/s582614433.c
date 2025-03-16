#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define long long type for convenience
#define ll long long

// Macro for iterating from l to r
#define rep(i,l,r) for(ll i=(l);i<(r);i++)

// Macro for iterating from l to r with step k
#define repp(i,l,r,k) for(ll i=(l);i<(r);i+=(k))

// Define a large constant for infinity
#define INF ((1LL<<62)-(1LL<<31))

// Macro to get the maximum of two values
#define max(p,q) ((p)>(q)?(p):(q))

// Macro to get the minimum of two values
#define min(p,q) ((p)<(q)?(p):(q))

// Macro to check the bit at position m in n
#define bit(n,m) (((n)>>(m))&1)

// Comparison function for sorting in ascending order
int upll(const void*a, const void*b) {
    return *(ll*)a < *(ll*)b ? -1 : *(ll*)a > *(ll*)b ? 1 : 0;
}

// Comparison function for sorting in descending order
int downll(const void*a, const void*b) {
    return *(ll*)a < *(ll*)b ? 1 : *(ll*)a > *(ll*)b ? -1 : 0;
}

// Function to sort an array in ascending order
void sortup(ll*a, int n) {
    qsort(a, n, sizeof(ll), upll);
}

// Function to sort an array in descending order
void sortdown(ll*a, int n) {
    qsort(a, n, sizeof(ll), downll);
}

// Function to compute (a^n) % m using modular exponentiation
ll pom(ll a, ll n, int m) {
    ll x = 1; // Initialize result
    for (a %= m; n; n /= 2) { // Loop until n is zero
        n & 1 ? x = x * a % m : 0; // If n is odd, multiply x by a
        a = a * a % m; // Square a
    }
    return x; // Return the result
}

// Define a large prime number for modulo operations
#define MOD 1000000007

// Macro to compute modular inverse using Fermat's little theorem
#define invp(a,p) pom(a,p-2,p)

// Structure to hold edge information
typedef struct edge {
    ll p; // Weight or value associated with the edge
    ll i; // Index of the edge
    char s[20]; // Name or identifier of the edge
} E;

// Comparison function for sorting edges
int esort(const void*a, const void*b) {
    E *p = (E*)a, *q = (E*)b;
    // First compare by string identifier
    if (strcmp((*p).s, (*q).s)) return strcmp((*p).s, (*q).s);
    // If identifiers are the same, compare by weight in descending order
    if ((*p).p < (*q).p) return 1;
    return -1; // Otherwise, return -1 for sorting
}

// Array to hold edge data
E data[100];
ll n, m; // Variables to hold the number of edges and other data

int main() {
    // Read the number of edges
    scanf("%lld", &n);
    
    // Read edge data from input
    rep(i, 0, n) {
        scanf(" %s%lld", data[i].s, &data[i].p); // Read string and weight
        data[i].i = i; // Store the original index
    }
    
    // Sort the edges based on the defined sorting criteria
    qsort(data, n, sizeof(E), esort);
    
    // Output the original indices of the sorted edges
    rep(i, 0, n) printf("%lld\n", data[i].i + 1);
}
