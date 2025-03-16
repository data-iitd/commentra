
#include <bits/stdc++.h>
using namespace std;

int main() {
    int num = 998244353;
    string line;
    getline(cin, line);
    int n = stoi(line);
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);
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
        double c = (a[n / 2] + a[n / 2 - 1]) / 2.0;
        double d = (b[n / 2] + b[n / 2 - 1]) / 2.0;
        cout << (int) (2 * (d - c) + 1) << endl;
    }
    return 0;
}
//END-OF-CODE