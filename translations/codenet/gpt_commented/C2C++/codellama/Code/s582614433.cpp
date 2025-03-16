#include <iostream>
#include <cstring>
#include <algorithm>

// Define long long type for convenience
using ll = long long;

// Macro for iterating from l to r
#define rep(i,l,r) for(ll i=(l);i<(r);i++)

// Macro for iterating from l to r with step k
#define repp(i,l,r,k) for(ll i=(l);i<(r);i+=(k))

// Define a large constant for infinity
const ll INF = (1LL<<62)-(1LL<<31);

// Macro to get the maximum of two values
#define max(p,q) ((p)>(q)?(p):(q))

// Macro to get the minimum of two values
#define min(p,q) ((p)<(q)?(p):(q))

// Macro to check the bit at position m in n
#define bit(n,m) (((n)>>(m))&1)

// Comparison function for sorting in ascending order
bool upll(const ll&a, const ll&b) {
    return a < b ? true : false;
}

// Comparison function for sorting in descending order
bool downll(const ll&a, const ll&b) {
    return a < b ? false : true;
}

// Function to sort an array in ascending order
void sortup(ll*a, int n) {
    std::sort(a, a + n, upll);
}

// Function to sort an array in descending order
void sortdown(ll*a, int n) {
    std::sort(a, a + n, downll);
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
const ll MOD = 1000000007;

// Macro to compute modular inverse using Fermat's little theorem
#define invp(a,p) pom(a,p-2,p)

// Structure to hold edge information
struct edge {
    ll p; // Weight or value associated with the edge
    ll i; // Index of the edge
    char s[20]; // Name or identifier of the edge
};

// Comparison function for sorting edges
bool esort(const edge&a, const edge&b) {
    // First compare by string identifier
    if (strcmp(a.s, b.s)) return strcmp(a.s, b.s) < 0;
    // If identifiers are the same, compare by weight in descending order
    return a.p < b.p;
}

// Array to hold edge data
edge data[100];
ll n, m; // Variables to hold the number of edges and other data

int main() {
    // Read the number of edges
    std::cin >> n;
    
    // Read edge data from input
    rep(i, 0, n) {
        std::cin >> data[i].s >> data[i].p; // Read string and weight
        data[i].i = i; // Store the original index
    }
    
    // Sort the edges based on the defined sorting criteria
    std::sort(data, data + n, esort);
    
    // Output the original indices of the sorted edges
    rep(i, 0, n) std::cout << data[i].i + 1 << std::endl;
}

