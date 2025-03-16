

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <cassert>
#include <iomanip>
#include <random>

using namespace std;

using lint = long long;

lint combi(int n, int k) {
    lint min = (lint)(k-1) * k / 2;
    lint max = (lint)(2*n-k+1) * k / 2;
    return max - min + 1;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    lint total = 0;
    for (int i = k; i <= n+1; i++) {
        lint comb = combi(n, i);
        total += comb;
        total %= (lint)1e9 + 7;
    }

    cout << total << endl;

    return 0;
}

