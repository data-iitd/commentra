
#include <bits/stdc++.h>
using namespace std;

string s() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (a[i]!= a[i - 1] && a[i] < 2 * a[i - 1]) {
            return "YES";
        }
    }
    return "NO";
}

int main() {
    cout << s() << endl;
    return 0;
}

END-OF-CODE