#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    int f = 1, c = 0;
    sort(l.begin(), l.end());
    for (int i = 0; i < n; i++) {
        if (l[i] > c) {
            c++;
        }
    }

    cout << c + 1 << endl;

    return 0;
}

