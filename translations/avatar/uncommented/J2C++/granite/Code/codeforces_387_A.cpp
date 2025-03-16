
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int h1 = stoi(s.substr(0, 2));
    int m1 = stoi(s.substr(3, 2));
    int h2 = stoi(t.substr(0, 2));
    int m2 = stoi(t.substr(3, 2));
    int h = h1 - h2;
    int m = m1 - m2;
    if (m < 0) {
        m += 60;
        h--;
    }
    if (h < 0) {
        h += 24;
    }
    cout << h << ":" << m << endl;
    return 0;
}
// END-OF-CODE