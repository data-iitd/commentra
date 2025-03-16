

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#define endl '\n'
typedef long long int ll;

using namespace std;

int main() {
    int n, q, l, r, win;
    cin >> n;
    set<int> s;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        s.insert(i);
    }
    cin >> q;
    while (q--) {
        cin >> l >> r >> win;
        l--;
        r--;
        win--;
        auto it = s.lower_bound(l);
        while (it!= s.end() && *it <= r) {
            ans[*it] = win;
            s.erase(it++);
        }
        ans[win] = 0;
        s.insert(win);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

