
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

const ll MOD = 100000007;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll lcm_all = 1;
    for (int i = 0; i < N; i++) {
        lcm_all = lcm(lcm_all, A[i]);
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += lcm_all / A[i];
    }
    ans %= MOD;
    cout << ans << endl;
    return 0;
}

