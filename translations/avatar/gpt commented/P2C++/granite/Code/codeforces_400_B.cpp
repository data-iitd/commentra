
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
    cout << (any_of(c.begin(), c.end(), [](int a) { return a < 0; })? -1 : c.size()) << endl;
}
// END-OF-CODE