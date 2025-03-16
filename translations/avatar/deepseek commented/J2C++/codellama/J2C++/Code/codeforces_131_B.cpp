
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    long cnt[21];
    long res = 0;

    cin >> n;

    for (int i = 0; i < 21; i++) {
        cnt[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x + 10]++;
    }

    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }

    res += (cnt[10] * (cnt[10] - 1)) / 2;

    cout << res << endl;

    return 0;
}

