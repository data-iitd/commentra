#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <numeric>
#include <functional>
#include <iomanip>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        if (n < a) {
            cout << "No" << endl;
            continue;
        }

        if (a == b) {
            if (n % a == 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            continue;
        }

        long long x = b / (b - a);
        if (n > x * a) {
            cout << "Yes" << endl;
            continue;
        }

        long long low = 1;
        long long high = x + 1;
        long long ans = 1;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (mid * a < n) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        if (n > (ans - 1) * b && n < ans * a) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}

