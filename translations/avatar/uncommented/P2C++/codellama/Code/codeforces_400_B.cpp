
#include <iostream>
#include <set>
#include <string>
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
    if (c.find(-1) != c.end()) {
        cout << -1 << endl;
    } else {
        cout << c.size() << endl;
    }
    return 0;
}

