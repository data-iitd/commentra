#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
#define rep(i,l,r) for(ll i=(l); i<(r); i++) // for loop with initialization, condition, and increment
#define repp(i,l,r,k) for(ll i=(l); i<(r); i+=(k)) // for loop with initialization, limit, increment, and loop variable name
#define INF ((1LL<<62)-(1LL<<31)) // constant value for infinity
#define max(p,q) ((p)>(q)?(p):(q)) // macro for finding maximum of two values
#define min(p,q) ((p)<(q)?(p):(q)) // macro for finding minimum of two values
#define bit(n,m) (((n)>>(m))&1) // macro for checking the bit at position m in binary representation of n
#define upll(a,b) return *(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0; // comparison function for qsort() to sort in ascending order
#define downll(a,b) return *(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0; // comparison function for qsort() to sort in descending order

ll pom(ll a, ll n, int m) { // function to calculate (a^n) % m using modular exponentiation
    ll x = 1;
    for (a %= m; n; n /= 2) {
        if (n & 1) x = x * a % m;
        a = a * a % m;
    }
    return x;
}

#define MOD 1000000007 // constant value for the modulo
#define invp(a,p) pom(a,p-2,p) // macro for calculating the modular inverse of a number a with respect to modulo p

// Data structure for an edge with source string, destination vertex, and weight
struct Edge {
    ll p; // destination vertex
    ll i; // index of the edge in the data array
    char s[20]; // source string
};

bool esort(const Edge &a, const Edge &b) { // comparison function for sorting edges
    int cmp = strcmp(a.s, b.s);
    if (cmp != 0) return cmp < 0; // compare source strings first
    return a.p > b.p; // if source strings are equal, compare destination vertices
}

int main() { // main function
    ll n; // number of vertices
    std::cin >> n; // read the number of vertices
    std::vector<Edge> data(n); // vector to store edges

    rep(i, 0, n) { // for each vertex
        std::cin >> data[i].s >> data[i].p; // read the source string and destination vertex
        data[i].i = i; // assign the index of the edge to the edge itself
    }

    std::sort(data.begin(), data.end(), esort); // sort the edges based on their source strings and destination vertices

    rep(i, 0, n) std::cout << data[i].i + 1 << std::endl; // print the indices of the sorted edges
}

