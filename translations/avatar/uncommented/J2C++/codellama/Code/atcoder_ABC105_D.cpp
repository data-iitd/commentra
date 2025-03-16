
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

class InputReader {
public:
    InputReader(const string& file_name) {
        freopen(file_name.c_str(), "r", stdin);
    }
    string nextString() {
        string s;
        cin >> s;
        return s;
    }
    int nextInt() {
        int x;
        cin >> x;
        return x;
    }
    vector<int> nextIntArray(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            cin >> res[i];
        }
        return res;
    }
};

class TaskD {
public:
    void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        vector<int> a = in.nextIntArray(n);
        map<int, int> dp;
        long ans = 0;
        int base = 0;
        for (int i = 0; i < n; i++) {
            base = (base - a[i] % m + m) % m;
            dp[((base + a[i]) % m)]++;
            ans += dp[base];
        }
        out << ans << endl;
    }
};

int main() {
    InputReader in("main.in");
    PrintWriter out("main.out");
    TaskD solver;
    solver.solve(1, in, out);
    out.close();
    return 0;
}

