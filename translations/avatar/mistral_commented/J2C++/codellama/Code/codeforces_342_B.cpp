
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    istringstream iss(input);
    int m, s, f;
    iss >> m >> s >> f;
    map<int, vector<int>> map;
    while (m--) {
        getline(cin, input);
        istringstream iss(input);
        int k, a, b;
        iss >> k >> a >> b;
        map[k] = {a, b};
    }
    string actions;
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    int cur = s;
    while (cur != f) {
        if (map.find(cur) != map.end()) {
            actions += 'X';
        } else {
            actions += M;
            cur += d;
        }
    }
    cout << actions << endl;
    return 0;
}

