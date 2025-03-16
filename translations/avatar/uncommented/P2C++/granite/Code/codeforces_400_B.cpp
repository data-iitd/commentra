
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> c;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        c.insert(s.find("S") - s.find("G"));
    }
    if (*c.begin() < 0) {
        cout << -1 << endl;
    } else {
        cout << c.size() << endl;
    }
    return 0;
}
// END-OF-CODE