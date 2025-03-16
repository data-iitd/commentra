
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string input;
    getline(cin, input);
    stringstream ss(input);
    int m, s, f;
    ss >> m >> s >> f;
    int maxT = -1;
    unordered_map<int, vector<int>> map;
    while (m--) {
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int k, a, b;
        ss >> k >> a >> b;
        maxT = max(maxT, k);
        map[k] = {a, b};
    }
    stringstream actions;
    char M = (s < f)? 'R' : 'L';
    int d = (s < f)? +1 : -1;
    int cur = s;
    int t = 1;
    while (t <= maxT) {
        if (map.find(t)!= map.end()) {
            a = map[t][0];
            b = map[t][1];
        }
        if (map.find(t)!= map.end() && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
            actions << 'X';
        } else {
            actions << M;
            cur += d;
        }
        if (cur == f) break;
        t++;
    }
    while (cur!= f) {
        actions << M;
        cur += d;
    }
    cout << actions.str() << endl;
    return 0;
}
//END-OF-CODE