
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int testCases; cin >> testCases;
    while (testCases--) {
        string s; cin >> s;
        if (s.find("A")!= string::npos && s.find("B")!= string::npos) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// END-OF-CODE

