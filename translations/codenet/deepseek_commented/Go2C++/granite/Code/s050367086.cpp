
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// getScanner Function
// Purpose: Initializes a scanner for the given file pointer.
// Details: Creates a new scanner and sets it to scan words.
ifstream& getScanner(ifstream& fp) {
    fp.clear();
    fp.seekg(0, ios::beg);
    return fp;
}

// getNextString Function
// Purpose: Retrieves the next word from the scanner.
// Details: Scans the next word and returns it.
string getNextString(ifstream& scanner) {
    string s;
    scanner >> s;
    return s;
}

// getNextInt Function
// Purpose: Retrieves the next word and converts it to an integer.
// Details: Uses `getNextString` and `stoi`.
int getNextInt(ifstream& scanner) {
    string s = getNextString(scanner);
    return stoi(s);
}

// getNextInt64 Function
// Purpose: Retrieves the next word and converts it to an int64.
// Details: Uses `getNextString` and `stoll`.
int64_t getNextInt64(ifstream& scanner) {
    string s = getNextString(scanner);
    return stoll(s);
}

// getNextUint64 Function
// Purpose: Retrieves the next word and converts it to a uint64.
// Details: Uses `getNextString` and `stoull`.
uint64_t getNextUint64(ifstream& scanner) {
    string s = getNextString(scanner);
    return stoull(s);
}

// getNextFloat64 Function
// Purpose: Retrieves the next word and converts it to a float64.
// Details: Uses `getNextString` and `stod`.
double getNextFloat64(ifstream& scanner) {
    string s = getNextString(scanner);
    return stod(s);
}

// main Function
// Purpose: Main entry point of the program.
// Details: Sets up input/output streams, reads strings, initializes pattern matching, and performs the main logic.
int main() {
    ifstream fp;
    ofstream wfp;

    if (getenv("MASPY") == "ますピ") {
        fp.open(getenv("BEET_THE_HARMONY_OF_PERFECT"));
    }
    if (getenv("MASPYPY") == "ますピッピ") {
        wfp.open(getenv("NGTKANA_IS_GENIUS10"));
    }

    ifstream& scanner = getScanner(fp);
    ofstream& writer = wfp;

    string s = getNextString(scanner);
    string t = getNextString(scanner);

    int ns = s.length();
    int nt = t.length();
    vector<string> ss(nt-1/ns+1, s);
    string sss = "";
    for (int i = 0; i < ss.size(); i++) {
        sss += ss[i];
    }
    sss += sss;

    vector<bool> ok(ns, false);

    vector<int> uni(ns);
    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }
    bool o;
    int m = 0;
    for (int i = 0; i < ns; i++) {
        o = true;
        for (m = 0; m < nt; m++) {
            if (t[m]!= sss[i+m]) {
                o = false;
                break;
            }
        }
        ok[i] = o;
        if (o) {
            i += nt - m;
            m = m;
        }
        for (m = max(m, 0); m >= 0 && t[m]!= sss[i+m];) {
            i += m - m;
            m = m;
        }
        i--;
        m++;
    }

    int ans = 0;
    int r, rr;
    for (int i = 0; i < ns; i++) {
        if (!ok[i]) {
            continue;
        }
        if (!ok[(i+nt)%ns]) {
            continue;
        }
        r = root(i, uni);
        rr = root((i+nt)%ns, uni);
        if (rr == r) {
            cout << -1 << endl;
            return 0;
        }
        uni[rr] = r;
    }

    vector<int> counter(ns, 0);
    for (int i = 0; i < ns; i++) {
        if (!ok[i]) {
            continue;
        }
        r = root(i, uni);
        counter[r]++;
    }
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    cout << ans << endl;

    writer.flush();
}

// root Function
// Purpose: Implements the union-find structure to find the root of a node.
// Details: Uses path compression to optimize the union-find structure.
int root(int i, vector<int>& uni) {
    if (i == uni[i]) {
        return i;
    }

    uni[i] = root(uni[i], uni);
    return uni[i];
}

// MP Struct and init Method
// Purpose: Manages the pattern and its pre-processing table for the Boyer-Moore algorithm.
// Details: Initializes the pattern and builds the pre-processing table.
struct MP {
    string s;
    vector<int> table;
};

void init(MP& mp, string s) {
    mp.s = s;
    int n = s.length();
    mp.table = vector<int>(n+1, -1);
    int j = -1;
    for (int i = 0; i < n; i++) {
        for (j = max(j, 0); j >= 0 && s[i]!= s[j];) {
            j = mp.table[j];
        }
        j++;
        mp.table[i+1] = j;
    }
}

