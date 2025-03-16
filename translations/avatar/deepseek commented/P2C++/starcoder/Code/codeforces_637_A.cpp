#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cctype>
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

    reverse(s.begin(), s.end());

    int c = -1, a = 0;
    for (auto i : w) {
        if (i.second == *max_element(w.begin(), w.end(), [](const pair<string, int> &a, const pair<string, int> &b) { return a.second < b.second; })) {
            if (s.end() - find(s.begin(), s.end(), i.first) > c) {
                a = i.first;
                c = s.end() - find(s.begin(), s.end(), i.first);
            }
        }
    }

    cout << a << endl;

    return 0;
}

