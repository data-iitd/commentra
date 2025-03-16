
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    string m;
    cin >> m;
    bool possible = true;
    set<string> s;
    for (int i = 0; i < m.length(); i++) {
        s.insert(m[i]);
    }
    for (auto i : s) {
        if (count(m.begin(), m.end(), i) >= n / 2 + 1) {
            possible = false;
            break;
        }
    }
    cout << (possible ? "YES" : "NO") << endl;
    return 0;
}

