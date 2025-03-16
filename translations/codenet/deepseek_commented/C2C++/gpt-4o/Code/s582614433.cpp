#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

// Define a long long integer type for convenience
using ll = long long;

// Define a large number to represent infinity
constexpr ll INF = (1LL << 62) - (1LL << 31);

// Define a macro to get the maximum of two values
#define max(p, q) ((p) > (q) ? (p) : (q))

// Define a macro to get the minimum of two values
#define min(p, q) ((p) < (q) ? (p) : (q))

// Define a structure to hold edge information
struct Edge {
    ll p;
    int i;
    char s[20];
};

// Function to sort edges based on the string and then by the long long value
bool esort(const Edge& a, const Edge& b) {
    int cmp = strcmp(a.s, b.s);
    if (cmp != 0) return cmp < 0;
    return a.p > b.p; // Sort in descending order of p
}

// Main function
int main() {
    // Read the number of edges
    ll n;
    std::cin >> n;

    // Array to hold edge data
    std::vector<Edge> data(n);

    // Read each edge's string and long long value, and store the index
    for (ll i = 0; i < n; ++i) {
        std::cin >> data[i].s >> data[i].p;
        data[i].i = i;
    }

    // Sort the edges using the custom esort function
    std::sort(data.begin(), data.end(), esort);

    // Print the indices of the edges in the sorted order
    for (ll i = 0; i < n; ++i) {
        std::cout << data[i].i + 1 << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
