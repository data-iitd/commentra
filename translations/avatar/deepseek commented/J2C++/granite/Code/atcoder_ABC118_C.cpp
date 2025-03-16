

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    if (n == 1) {
        int x;
        cin >> x;
        cout << x << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    if (a.back() == 0) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    while (true) {
        if (a.size() == 1) {
            ans = a.front();
            break;
        }
        a = func(a);
    }
    cout << ans << endl;
    return 0;
}

vector<int> func(vector<int> a) {
    vector<int> b = a;
    int min = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == 0) {
            b.erase(b.begin() + i);
            i--;
        } else {
            if (min!= 0) {
                b[i] %= min;
                if (b[i] == 1) {
                    cout << 1 << endl;
                    exit(0);
                }
            } else {
                min = b[i];
            }
        }
    }
    sort(b.begin(), b.end());
    return b;
}

