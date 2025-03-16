
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int N = 1e5 + 5;
    long cnt[21];
    for (int i = 0; i < n; i++) {
        cnt[scan.nextInt() + 10]++;
    }
    long res = 0;
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }
    res += (cnt[10] * (cnt[10] - 1)) / 2;
    cout << res;
    return 0;
}

