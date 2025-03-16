#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to get the next string from the input
string getNextString(istringstream &scanner) {
    string word;
    scanner >> word;
    return word;
}

// Function to get the next integer from the input
int getNextInt(istringstream &scanner) {
    int i;
    scanner >> i;
    return i;
}

// Function to get the next long long integer from the input
long long getNextInt64(istringstream &scanner) {
    long long i;
    scanner >> i;
    return i;
}

// Function to get the next unsigned long long integer from the input
unsigned long long getNextUint64(istringstream &scanner) {
    unsigned long long i;
    scanner >> i;
    return i;
}

// Function to get the next double from the input
double getNextFloat64(istringstream &scanner) {
    double i;
    scanner >> i;
    return i;
}

// Function to find the root of a node in the union-find structure
int root(int i, vector<int> &uni) {
    if (i == uni[i]) {
        return i;
    }
    uni[i] = root(uni[i], uni);
    return uni[i];
}

// Struct to manage the pattern and its pre-processing table for the Boyer-Moore algorithm
struct MP {
    string s;
    vector<int> table;

    void init(const string &s) {
        this->s = s;
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

int main() {
    string input;
    getline(cin, input);
    istringstream scanner(input);

    string s = getNextString(scanner);
    string t = getNextString(scanner);

    int ns = s.length();
    int nt = t.length();
    vector<string> ss((nt - 1) / ns + 1, s);

    string sss = string(ss.begin(), ss.end()) + string(ss.begin(), ss.end());

    vector<bool> ok(ns, false);
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
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
