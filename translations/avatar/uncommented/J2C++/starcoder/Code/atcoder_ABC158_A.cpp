#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testNumber;
    cin >> testNumber;
    while (testNumber--) {
        string s;
        cin >> s;
        if (s.find("A")!= string::npos && s.find("B")!= string::npos) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
