
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <random>
#include <chrono>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
typedef pair<double, double> Pd;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> s;
    int ng = 0, ok = n;
    while (ok - ng > 1) {
        int k = (ng + ok) / 2;
        s.clear();
        int current = 0;
        for (int ai : a) {
            if (ai <= current) {
                if (k == 1) {
                    ok = k;
                    break;
                }
                while (!s.empty() && s.rbegin()->first >= ai) {
                    s.erase(prev(s.end()));
                }
                int p = ai - 1;
                while (true) {
                    if (p < 0) {
                        ok = k;
                        break;
                    }
                    int sp = s[p] + 1;
                    s[p] = sp;
                    if (sp == k) {
                        s.erase(p);
                        p--;
                    } else {
                        break;
                    }
                }
            }
            current = ai;
        }
        if (ok == k) break;
    }
    cout << ok << endl;
    return 0;
}
// END-OF-CODE