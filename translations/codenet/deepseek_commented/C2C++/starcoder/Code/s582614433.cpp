#include <bits/stdc++.h>

using namespace std;

// Define a long long integer type for convenience
typedef long long ll;

// Define a macro for a simple loop
#define rep(i, l, r) for (ll i = (l); i < (r); i++)

// Define a macro for a loop with a step
#define repp(i, l, r, k) for (ll i = (l); i < (r); i += (k))

// Define a large number to represent infinity
#define INF ((1LL << 62) - (1LL << 31))

// Define a macro to get the maximum of two values
#define max(p, q) ((p) > (q)? (p) : (q))

// Define a macro to get the minimum of two values
#define min(p, q) ((p) < (q)? (p) : (q))

// Define a macro to check if a bit is set in a number
#define bit(n, m) (((n) >> (m)) & 1)

// Function to sort in ascending order
int upll(const void* a, const void* b) {
    return *(ll*)a < *(ll*)b? -1 : *(ll*)a > *(ll*)b? 1 : 0;
}

// Function to sort in descending order
int downll(const void* a, const void* b) {
    return *(ll*)a < *(ll*)b? 1 : *(ll*)a > *(ll*)b? -1 : 0;
}

// Function to sort an array of long long values in ascending order using qsort
void sortup(ll* a, int n) {
    qsort(a, n, sizeof(ll), upll);
}

// Function to sort an array of long long values in descending order using qsort
void sortdown(ll* a, int n) {
    qsort(a, n, sizeof(ll), downll);
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
typedef struct edge {
    ll p;
    int i;
    string s;
} E;

// Function to sort edges based on the string and then by the long long value
int esort(const void* a, const void* b) {
    E* p = (E*)a, * q = (E*)b;
    int cmp = p->s.compare(q->s);
    if (cmp) return cmp;
    if (p->p < q->p) return 1;
    return -1;
}

// Array to hold edge data
E data[100];

// Variables to hold the number of edges
ll n, m;

// Main function
int main() {
    // Read the number of edges
    cin >> n;

    // Read each edge's string and long long value, and store the index
    rep(i, 0, n) {
        cin >> data[i].s >> data[i].p;
        data[i].i = i;
    }

    // Sort the edges using qsort and the custom esort function
    qsort(data, n, sizeof(E), esort);

    // Print the indices of the edges in the sorted order
    rep(i, 0, n) cout << data[i].i + 1 << endl;
}

