#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class MP {
public:
    string s;
    vector<int> table;

    void init(const string& str) {
        s = str;
        int n = s.length();
        table.resize(n + 1);
        table[0] = -1;
        int j = -1;
        for (int i = 0; i < n; i++) {
            while (j >= 0 && s[i] != s[j]) {
                j = table[j];
            }
            j++;
            table[i + 1] = j;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int ns = s.length();
    int nt = t.length();
    vector<string> ss((nt - 1) / ns + 1, s);

    string sss = string(ss.begin(), ss.end()) + string(ss.begin(), ss.end());

    vector<bool> ok(ns);
    vector<int> uni(ns);
    MP mp;
    mp.init(t);
    int m = 0;

    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }

    for (int i = 0; i < ns; i++) {
        bool o = true;
        m = 0;
        while (m < nt) {
            if (t[m] != sss[i + m]) {
                o = false;
                break;
            }
            m++;
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
    int r, rr;
    for (int i = 0; i < ns; i++) {
        if (!ok[i]) continue;
        if (!ok[(i + nt) % ns]) continue;
        r = root(i, uni);
        rr = root((i + nt) % ns, uni);
        if (rr == r) {
            cout << -1 << endl;
            return 0;
        }
        uni[rr] = r;
    }

    vector<int> counter(ns, 0);
    for (int i = 0; i < ns; i++) {
        r = root(i, uni);
        if (!ok[r]) continue;
        counter[r]++;
    }
    for (int i = 0; i < ns; i++) {
        ans = max(ans, counter[i]);
    }

    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
