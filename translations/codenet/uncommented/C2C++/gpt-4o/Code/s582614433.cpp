#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define ll long long
#define MOD 1000000007

struct Edge {
    ll p;
    int i;
    char s[20];
};

bool esort(const Edge &a, const Edge &b) {
    int cmp = strcmp(a.s, b.s);
    if (cmp != 0) return cmp < 0;
    return a.p > b.p; // Sort in descending order for p
}

ll pom(ll a, ll n, int m) {
    ll x = 1;
    a %= m;
    while (n) {
        if (n & 1) x = x * a % m;
        a = a * a % m;
        n /= 2;
    }
    return x;
}

int main() {
    ll n;
    std::cin >> n;
    std::vector<Edge> data(n);
    
    for (ll i = 0; i < n; ++i) {
        std::cin >> data[i].s >> data[i].p;
        data[i].i = i;
    }
    
    std::sort(data.begin(), data.end(), esort);
    
    for (ll i = 0; i < n; ++i) {
        std::cout << data[i].i + 1 << std::endl;
    }
    
    return 0;
}

// <END-OF-CODE>
