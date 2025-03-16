
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <random>
#include <time.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum > n) {
        cout << -1 << endl;
    } else {
        cout << n - sum << endl;
    }
    return 0;
}
