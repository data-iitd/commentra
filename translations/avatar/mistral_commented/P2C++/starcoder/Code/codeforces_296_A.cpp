#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string m;
    cin >> m;
    bool possible = true;
    for (char i : set<char>(m)) {
        if (m.count(i) >= n / 2 + 1) {
            possible = false;
            break;
        }
    }
    cout << (possible? "YES" : "NO") << endl;
    return 0;
}
