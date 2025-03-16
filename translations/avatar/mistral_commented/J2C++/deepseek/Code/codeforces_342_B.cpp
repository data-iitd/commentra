#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;

int main() {
    int m, s, f;
    cin >> m >> s >> f;
    int maxT = -1;

    map<int, list<int>> map;

    for (int i = 0; i < m; i++) {
        int k, a, b;
        cin >> k >> a >> b;
        map[k].push_back(a);
        map[k].push_back(b);
        maxT = max(maxT, k);
    }

    string actions;
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    int cur = s;

    for (int t = 1; t <= maxT; t++) {
        if (map.find(t) != map.end()) {
            auto it = map.find(t);
            int a = it->second.front();
            int b = it->second.back();

            if ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b)) {
                actions += 'X';
            } else {
                actions += M;
                cur += d;
            }

            if (cur == f) {
                break;
            }
        } else {
            actions += M;
            cur += d;
        }
    }

    while (cur != f) {
        actions += M;
        cur += d;
    }
    cout << actions << endl;

