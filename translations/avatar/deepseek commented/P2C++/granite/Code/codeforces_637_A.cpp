
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    map<string, int> w;
    string t;
    while (getline(cin, t,'')) {
        w[t]++;
    }
    reverse(s.begin(), s.end());
    int c = -1, a = 0;
    for (auto i : w) {
        if (i.second == *max_element(w.begin(), w.end(), [](const pair<string, int>& a, const pair<string, int>& b) { return a.second < b.second; })) {
            if (s.find(i.first) > c) {
                a = i.first;
                c = s.find(i.first);
            }
        }
    }
    cout << a << endl;
    return 0;
}

