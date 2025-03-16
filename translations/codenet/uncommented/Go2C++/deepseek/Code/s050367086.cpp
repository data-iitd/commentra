#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace std;

class MP {
public:
    string s;
    vector<int> table;
    void init(const string& s) {
        this->s = s;
        int n = s.size();
        table.resize(n + 1, 0);
        int j = 0;
        for (int i = 1; i < n; i++) {
            while (j > 0 && s[i] != s[j]) {
                j = table[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            table[i] = j;
        }
    }
};

int root(int i, vector<int>& uni) {
    if (i == uni[i]) {
        return i;
    }
    uni[i] = root(uni[i], uni);
    return uni[i];
}

int main() {
    string s, t;
    cin >> s >> t;

    int ns = s.size();
    int nt = t.size();
    vector<string> ss(ns, s);

    string sss = "";
    for (int i = 0; i < ns; i++) {
        sss += ss[i];
    }
    for (int i = 0; i < ns; i++) {
        sss += ss[i];
    }

    vector<bool> ok(ns, false);
    vector<int> uni(ns);
    MP mp;
    mp.init(t);
    int m = 0;
    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }
    bool o;
    for (int i = 0; i < ns; i++) {
        o = true;
        for (m = 0; m < nt; m++) {
            if (t[m] != sss[i + m]) {
                o = false;
                break;
            }
        }
        ok[i] = o;
        if (o) {
            i += nt - mp.table[m];
            m = mp.table[m];
        }
        while (m >= 0 && t[m] != sss[i + m]) {
            i += m - mp.table[m];
            m = mp.table[m];
        }
        i--;
        m++;
    }

    int ans = 0;
    for (int i = 0; i < ns; i++) {
        if (!ok[i]) continue;
        if (!ok[(i + nt) % ns]) continue;
        int r = root(i, uni);
        int rr = root((i + nt) % ns, uni);
        if (rr == r) {
            cout << -1 << endl;
            return 0;
        }
        uni[rr] = r;
    }

    vector<int> counter(ns, 0);
    for (int i = 0; i < ns; i++) {
        int r = root(i, uni);
        if (!ok[r]) continue;
        counter[r]++;
    }
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    cout << ans << endl;

    return 0;
}

