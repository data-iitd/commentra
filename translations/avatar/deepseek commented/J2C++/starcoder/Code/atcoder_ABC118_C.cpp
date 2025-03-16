
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[n - 1] == 0) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    while (true) {
        if (a.size() == 1) {
            ans = a[0];
            break;
        }
        a = func(a);
    }
    cout << ans << endl;
    return 0;
}

int func(vector<int> &a) {
    vector<int> a1 = a;
    int min = 0;
    for (int i = 0; i < a1.size(); i++) {
        if (a1[i] == 0) {
            a1.erase(a1.begin() + i);
            i--;
        } else {
            if (min!= 0) {
                a1[i] = a1[i] % min;
                if (a1[i] == 1) {
                    cout << 1 << endl;
                    return 0;
                }
            } else {
                min = a1[i];
            }
        }
    }
    sort(a1.begin(), a1.end());
    return a1;
}

