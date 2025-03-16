
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll combi(ll N, ll K) {
    ll a = 1;
    for (ll i = 0; i < K; i++) {
        a *= N - i;
    }
    for (ll j = 0; j < K; j++) {
        a /= j + 1;
    }
    return a;
}

int main() {
    ll N, P;
    cin >> N >> P;
    vector<ll> lis(N);
    for (ll i = 0; i < N; i++) {
        cin >> lis[i];
        lis[i] %= 2;
    }
    ll one = count(lis.begin(), lis.end(), 1);
    ll zero = count(lis.begin(), lis.end(), 0);
    ll pattern_a = 0, pattern_b = 0;
    for (ll j = 0; j <= zero; j++) {
        pattern_b += combi(zero, j);
    }
    ll time = 0;
    while (time <= one) {
        if (time % 2 == P) {
            pattern_a += combi(one, time);
        }
        time++;
    }
    cout << (ll)(pattern_a * pattern_b) << endl;
    return 0;
}

