

#include <bits/stdc++.h>
using namespace std;

int main() {
    int num = 998244353;
    string s;
    getline(cin, s);
    int n = stoi(s);
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        stringstream ss(s);
        int x, y;
        ss >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n % 2 == 1) {
        cout << b[n / 2] - a[n / 2] + 1 << endl;
    } else {
        double b_avg = (a[n / 2] + a[n / 2 - 1]) / 2.0;
        double c_avg = (b[n / 2] + b[n / 2 - 1]) / 2.0;
        cout << (int)(2 * (c_avg - b_avg) + 1) << endl;
    }
    return 0;
}

