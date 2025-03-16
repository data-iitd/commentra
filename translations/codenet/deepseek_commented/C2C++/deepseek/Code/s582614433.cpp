#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Define a long long integer type for convenience
#define ll long long

// Define a macro for a simple loop
#define rep(i, l, r) for (ll i = (l); i < (r); i++)

// Define a macro for a loop with a step
#define repp(i, l, r, k) for (ll i = (l); i < (r); i += (k))

// Define a large number to represent infinity
#define INF ((1LL << 62) - (1LL << 31))

// Define a macro to get the maximum of two values
#define max(p, q) ((p) > (q) ? (p) : (q))

// Define a macro to get the minimum of two values
#define min(p, q) ((p) < (q) ? (p) : (q))

// Define a macro to check if a bit is set in a number
#define bit(n, m) (((n) >> (m)) & 1)

// Function to sort in ascending order
bool upll(const ll& a, const ll& b) {
    return a < b;
}

// Function to sort in descending order
bool downll(const ll& a, const ll& b) {
    return a > b;
}

// Function to sort an array of long long values in ascending order using sort
void sortup(std::vector<ll>& a) {
    std::sort(a.begin(), a.end(), upll);
}

// Function to sort an array of long long values in descending order using sort
void sortdown(std::vector<ll>& a) {
    std::sort(a.begin(), a.end(), downll);
}

// Function to perform modular exponentiation
ll pom(ll a, ll n, int m) {
    ll x = 1;
    a %= m;
    for (; n; n /= 2) {
        if (n & 1) x = x * a % m;
        a = a * a % m;
    }
    return x;
}

// Define a modulo value
#define MOD 1000000007

// Function to compute the modular multiplicative inverse
#define invp(a, p) pom(a, p - 2, p)

// Define a structure to hold edge information
struct Edge {
    ll p;
    int i;
    std::string s;
};

// Function to sort edges based on the string and then by the long long value
bool esort(const Edge& a, const Edge& b) {
    if (a.s != b.s) return a.s < b.s;
    return a.p > b.p;
}

// Vector to hold edge data
std::vector<Edge> data(100);

// Variables to hold the number of edges
ll n, m;

// Main function
int main() {
    // Read the number of edges
    std::cin >> n;

    // Read each edge's string and long long value, and store the index
    rep(i, 0, n) {
        std::cin >> data[i].s >> data[i].p;
        data[i].i = i;
    }

    // Sort the edges using sort and the custom esort function
    std::sort(data.begin(), data.begin() + n, esort);

    // Print the indices of the edges in the sorted order
    rep(i, 0, n) std::cout << data[i].i + 1 << '\n';
}
