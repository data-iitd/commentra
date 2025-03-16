#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x, y;
    int s1 = 0, s2 = 0;
    char ch[n];
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        int temp1 = s1 + x;
        int temp2 = s2 + y;
        if (abs(temp1 - temp2) <= 500) {
            s1 += x;
            ch[i] = 'A';
        } else if (abs(temp1 - s2) <= 500) {
            s2 += y;
            ch[i] = 'G';
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    string ans = "";
    ans += ch;
    cout << ans << endl;
    return 0;
}

