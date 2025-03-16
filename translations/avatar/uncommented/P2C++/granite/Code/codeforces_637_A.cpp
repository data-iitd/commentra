
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    unordered_map<char, int> m;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        m[c]++;
    }
    char max_char ='';
    int max_count = 0;
    for (auto it = m.begin(); it!= m.end(); it++) {
        if (it->second > max_count) {
            max_char = it->first;
            max_count = it->second;
        }
    }
    cout << max_char << endl;
    return 0;
}

