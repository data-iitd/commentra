#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = s.substr(0, s.size() - 1);
    vector<string> v;
    v.push_back(s);
    int max_count = 0;
    for (int i = 0; i < v.size(); i++) {
        int count = 0;
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == 'a') {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        int count = 0;
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == 'a') {
                count++;
            }
        }
        if (count == max_count) {
            cout << v[i][v[i].size() - 1];
        }
    }
    return 0;
}

