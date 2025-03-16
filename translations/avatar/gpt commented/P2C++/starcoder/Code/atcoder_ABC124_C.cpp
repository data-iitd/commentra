#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (s[i] == '0') even++;
            else odd++;
        } else {
            if (s[i] == '1') even++;
            else odd++;
        }
    }
    cout << min(n - even, n - odd) << endl;
    return 0;
}

