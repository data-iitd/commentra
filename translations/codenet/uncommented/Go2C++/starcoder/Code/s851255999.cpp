#include <bits/stdc++.h>
using namespace std;

int main() {
    // Your code here!
    int n;
    cin >> n;
    vector<pair<int,int>> ws(n);
    for (int i = 0; i < n; i++) {
        int a, n;
        cin >> a >> n;
        ws[i] = {a,n};
    }
    sort(ws.begin(), ws.end());

    int sum = 0;
    for (auto w : ws) {
        sum += w.second;
        if (sum > w.first) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}

