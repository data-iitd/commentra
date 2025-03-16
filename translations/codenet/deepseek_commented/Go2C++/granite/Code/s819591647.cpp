
//problem_b.cpp

#include <bits/stdc++.h>

using namespace std;

const int constMod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        double rate = (double)sum / (4 * m);
        if ((double)a[i] >= rate) {
            count++;
        }
    }

    if (count >= m) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

// 