#include <bits/stdc++.h>

using namespace std;

// Define long long type for convenience
typedef long long ll;

// Define a large constant for infinity
const ll INF = (1LL << 62) - (1LL << 31);

// Define a large prime number for modulo operations
const ll MOD = 1000000007;

// Structure to hold edge information
struct edge {
    ll p; // Weight or value associated with the edge
    ll i; // Index of the edge
    string s; // Name or identifier of the edge
};

// Array to hold edge data
edge data[100];
ll n, m; // Variables to hold the number of edges and other data

int main() {
    // Read the number of edges
    cin >> n;
    
    // Read edge data from input
    rep(i, 0, n) {
        cin >> data[i].s >> data[i].p; // Read string and weight
        data[i].i = i; // Store the original index
    }
    
    // Sort the edges based on the defined sorting criteria
    sort(data, data + n, [](edge a, edge b) {
        // First compare by string identifier
        if (a.s!= b.s) return a.s < b.s;
        // If identifiers are the same, compare by weight in descending order
        if (a.p < b.p) return 1;
        return -1; // Otherwise, return -1 for sorting
    });
    
    // Output the original indices of the sorted edges
    rep(i, 0, n) cout << data[i].i + 1 << endl;
}

