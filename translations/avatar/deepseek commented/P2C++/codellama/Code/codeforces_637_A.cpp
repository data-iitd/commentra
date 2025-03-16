#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    map<string, int> w;
    for (int i = 0; i < n; i++) {
        w[s[i]]++;
    }

    int c = -1, a = 0;
    for (auto i : w) {
        if (i.second == max(w.begin(), w.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second;
        })->second) {
            if (find(s.begin(), s.end(), i.first) - s.begin() > c) {
                a = i.first;
                c = find(s.begin(), s.end(), i.first) - s.begin();
            }
        }
    }

    cout << a << endl;

    return 0;
}

