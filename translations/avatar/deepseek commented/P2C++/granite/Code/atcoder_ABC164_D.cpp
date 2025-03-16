

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int l = 2019;
    cin >> s;
    vector<int> m(l + 1, 1);
    int a = 0, r = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        a = (a + (s[i] - '0') * pow(10, s.size() - i - 1, l)) % l;
        r += m[a];
        m[a]++;
    }
    cout << r << endl;
    return 0;
}
// END-OF-CODE