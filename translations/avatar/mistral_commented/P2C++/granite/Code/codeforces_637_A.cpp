
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    map<string, int> m;
    string temp;
    while (n--) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> temp) {
            m[temp]++;
        }
    }
    string ans = "";
    int max_count = 0;
    for (auto it : m) {
        if (it.second > max_count) {
            ans = it.first;
            max_count = it.second;
        }
    }
    cout << ans << endl;
    return 0;
}

