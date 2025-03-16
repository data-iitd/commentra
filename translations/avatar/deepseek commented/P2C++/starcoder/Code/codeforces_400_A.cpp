#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        int a = 0, b = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'O') {
                a++;
            } else {
                b++;
            }
        }
        if(a == b) {
            cout << 0 << endl;
        } else {
            cout << 1 << " ";
            if(a > b) {
                cout << a << "x" << b << endl;
            } else {
                cout << b << "x" << a << endl;
            }
        }
    }
    return 0;
}

