#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string m;
    cin >> m;
    bool possible = true;
    vector<string> v;
    stringstream ss(m);
    string s;
    while (getline(ss, s, ' ')) {
        v.push_back(s);
    }
    for (int i = 0; i < v.size(); i++) {
        if (count(v.begin(), v.end(), v[i]) >= n / 2 + 1) {
            possible = false;
            break;
        }
    }
    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

