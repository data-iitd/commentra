#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    getline(cin, input);
    stringstream ss(input);
    int m, s, f;
    ss >> m >> s >> f;

    int maxT = -1;
    map<int, vector<int>> map;

    while (m > 0) {
        string mth;
        getline(cin, mth);
        stringstream mss(mth);
        int k, a, b;
        mss >> k >> a >> b;
        map[k] = {a, b};
        maxT = max(maxT, k);
        m--;
    }

    string actions;
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    int cur = s;
    int a = -1, b = -1;

    for (int t = 1; t <= maxT; t++) {
        if (map.find(t) != map.end()) {
            a = map[t][0];
            b = map[t][1];
        }
        if (map.find(t) != map.end() && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
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

// <END-OF-CODE>
