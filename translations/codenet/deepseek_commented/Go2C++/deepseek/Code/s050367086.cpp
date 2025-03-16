#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Scanner {
public:
    Scanner(istream& is) : is(is) {}

    string nextString() {
        string word;
        is >> word;
        return word;
    }

    int nextInt() {
        return stoi(nextString());
    }

    int64_t nextInt64() {
        return stoll(nextString());
    }

    uint64_t nextUint64() {
        return stoull(nextString());
    }

    double nextFloat64() {
        return stod(nextString());
    }

private:
    istream& is;
};

class MP {
public:
    void init(const string& s) {
        this->s = s;
        int n = s.size();
        table.resize(n + 1, -1);
        int j = -1;
        for (int i = 0; i < n; i++) {
            while (j >= 0 && s[i] != s[j]) {
                j = table[j];
            }
            j++;
            table[i + 1] = j;
        }
    }

    string s;
    vector<int> table;
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

    ifstream ifp;
    ofstream ofp;
    ifp.open("/dev/stdin");
    ofp.open("/dev/stdout");

    Scanner scanner(ifp);
    ofstream* writer = new ofstream(ofp.rdbuf());

    string s = scanner.nextString();
    string t = scanner.nextString();

    int ns = s.size();
    int nt = t.size();
    vector<string> ss(ns);
    for (int i = 0; i < ns; i++) {
        ss[i] = s;
    }

    string sss = string(2 * ns, ' ') + string(ns, ' ') + string(ns, ' ');
    sss = sss.substr(ns) + sss.substr(0, ns);

    vector<bool> ok(ns);
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

    vector<int> counter(ns);
    for (int i = 0; i < ns; i++) {
        r = root(i, uni);
        if (!ok[r]) continue;
        counter[r]++;
    }
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    cout << ans << endl;

    delete writer;
    return 0;
}
