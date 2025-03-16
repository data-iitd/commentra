#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// Define long long type for convenience
#define ll long long

// Define a large constant for infinity
#define INF ((1LL<<62)-(1LL<<31))

// Macro to get the maximum of two values
#define max(p,q) ((p)>(q)?(p):(q))

// Macro to get the minimum of two values
#define min(p,q) ((p)<(q)?(p):(q))

// Function to compute (a^n) % m using modular exponentiation
ll pom(ll a, ll n, int m) {
    ll x = 1; // Initialize result
    for (a %= m; n; n /= 2) { // Loop until n is zero
        if (n & 1) x = x * a % m; // If n is odd, multiply x by a
        a = a * a % m; // Square a
    }
    return x; // Return the result
}

// Define a large prime number for modulo operations
#define MOD 1000000007

// Structure to hold edge information
struct Edge {
    ll p; // Weight or value associated with the edge
    ll i; // Index of the edge
    char s[20]; // Name or identifier of the edge
};

// Comparison function for sorting edges
bool esort(const Edge &p, const Edge &q) {
    // First compare by string identifier
    if (strcmp(p.s, q.s)) return strcmp(p.s, q.s) < 0;
    // If identifiers are the same, compare by weight in descending order
    return p.p > q.p;
}

int main() {
    ll n; // Variable to hold the number of edges
    // Read the number of edges
    cin >> n;
    
    // Vector to hold edge data
    vector<Edge> data(n);
    
    // Read edge data from input
    for (ll i = 0; i < n; i++) {
        cin >> data[i].s >> data[i].p; // Read string and weight
        data[i].i = i; // Store the original index
    }
    
    // Sort the edges based on the defined sorting criteria
    sort(data.begin(), data.end(), esort);
    
    // Output the original indices of the sorted edges
    for (ll i = 0; i < n; i++) {
        cout << data[i].i + 1 << endl;
    }

    return 0;
}

// <END-OF-CODE>
