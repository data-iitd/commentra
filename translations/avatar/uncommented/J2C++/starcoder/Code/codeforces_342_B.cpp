#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, s, f, maxT;
    cin >> m >> s >> f;
    maxT = -1;
    map<int, vector<int>> map;
    while (m > 0) {
        int k;
        cin >> k;
        map[k] = vector<int>(2);
        cin >> map[k][0] >> map[k][1];
        maxT = max(maxT, k);
        m--;
    }
    string actions;
    char M = (s < f)? 'R' : 'L';
    int d = (s < f)? +1 : -1;
    int cur = s;
    int a = -1, b = -1;
    for (int t = 1; t <= maxT; t++) {
        if (map.count(t)) {
            a = map[t][0];
            b = map[t][1];
        }
        if (map.count(t) && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
            actions.push_back('X');
        } else {
            actions.push_back(M);
            cur += d;
        }
        if (cur == f) break;
    }
    while (cur!= f) {
        actions.push_back(M);
        cur += d;
    }
    cout << actions << endl;
    return 0;
}
