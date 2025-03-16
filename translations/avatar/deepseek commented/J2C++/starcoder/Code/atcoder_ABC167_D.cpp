
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    int cur = 0, next = 0;
    set<int> used;
    while (used.find(next) == used.end()) {
        used.insert(next);
        int temp = next;
        next = a[next];
        a[temp] = -1;
        cur++;
    }
    long a = (long)cur - idx[next];
    long b = (long)idx[next];
    int ans = (int)((10000 * a + k - b) % a + b);
    if (b > k) ans = (int)k;
    cout << pos[ans] + 1 << endl;
    return 0;
}

