
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    map<string, int> w;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        w[s[i]]++;
    }
    string a = "";
    int c = -1;
    for (auto i : w) {
        if (i.second > c) {
            a = i.first;
            c = i.second;
        }
    }
    cout << a << endl;
    return 0;
}

