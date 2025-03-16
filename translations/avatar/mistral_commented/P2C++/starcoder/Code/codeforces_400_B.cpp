#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> c;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int index_S = s.find('S');
        int index_G = s.find('G');

        int difference = index_S - index_G;
        c.insert(difference);
    }

    cout << (any_of(c.begin(), c.end(), [](int a) { return a < 0; })? -1 : c.size()) << endl;

    return 0;
}

