#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string d = "";
        for (char c : s) {
            switch (c) {
                case '0':
                    d += "0";
                    break;
                case '1':
                    d += "1";
                    break;
                case 'B':
                    if (d.length() > 0) {
                        d.pop_back();
                    }
                    break;
            }
        }
        cout << d << "\n";
    }
    return 0;
}
