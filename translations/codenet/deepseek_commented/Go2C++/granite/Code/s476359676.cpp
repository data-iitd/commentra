

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <bitset>
#include <numeric>
#include <cctype>
#include <utility>
#include <random>
#include <chrono>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    int aPrev = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > i || a > aPrev + 1) {
            cout << -1 << endl;
            return 0;
        }
        if (a == aPrev + 1) {
            ans++;
        } else {
            ans += a;
        }
        aPrev = a;
    }
    cout << ans << endl;

    return 0;
}

