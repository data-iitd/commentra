
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int m, s, f;
    cin >> m >> s >> f;
    map<int, vector<int>> map;
    for (int i = 0; i < m; i++) {
        int k, a, b;
        cin >> k >> a >> b;
        map[k] = {a, b};
    }
    string actions;
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    int cur = s;
    int a = -1, b = -1;
    for (int t = 1; t <= m; t++) {
        if (map.find(t) != map.end()) {
            a = map[t][0];
            b = map[t][1];
        }
        if (map.find(t) != map.end() && (cur >= a && cur <= b || cur + d >= a && cur + d <= b)) {
            actions += 'X';
        } else {
            actions += M;
            cur += d;
        }
        if (cur == f) break;
    }
    while (cur != f) {
        actions += M;
        cur += d;
    }
    cout << actions << endl;
    return 0;
}

