
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int m, s, f, maxT;
    cin >> m >> s >> f;
    map<int, vector<int>> map;
    maxT = -1;
    while (m > 0) {
        int k;
        cin >> k;
        map[k] = vector<int>();
        map[k].push_back(0);
        map[k].push_back(0);
        maxT = max(maxT, k);
        m--;
    }
    string actions;
    char M = (s < f)? 'R' : 'L';
    int d = (s < f)? 1 : -1;
    int cur = s;
    int a, b;
    for (int t = 1; t <= maxT; t++) {
        if (map.find(t)!= map.end()) {
            a = map[t][0];
            b = map[t][1];
            if (map.find(t)!= map.end() && (cur >= a && cur <= b || cur + d >= a && cur + d <= b)) {
                actions.push_back('X');
            } else {
                actions.push_back(M);
                cur += d;
            }
            if (cur == f) {
                break;
            }
        } else {
            actions.push_back(M);
            cur += d;
        }
    }
    while (cur!= f) {
        actions.push_back(M);
        cur += d;
    }
    cout << actions << endl;
    return 0;
}

