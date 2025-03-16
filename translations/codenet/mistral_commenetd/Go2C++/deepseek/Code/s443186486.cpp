#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int combi(int n, int r) {
    int c = 1;
    for (int i = 1; i <= r; i++) {
        c = c * (n - i + 1) / i;
    }
    return c;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> s(n + 1, 0);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }

    sort(s.begin(), s.end());

    int ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == s[i + 1]) {
            count++;
        } else {
            if (count > 0) {
                ans += combi(count + 1, 2);
                count = 0;
            }
        }
    }
    if (count > 0) {
        ans += combi(count + 1, 2);
    }

    cout << ans << endl;
    return 0;
}

