
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class TaskD {
public:
    void solve(int testNumber, istream &in, ostream &out) {
        int n, m;
        in >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            in >> a[i];
        }
        map<int, int> dp;
        long long ans = 0;
        int base = 0;
        for (int i = 0; i < n; i++) {
            base = (base - a[i] % m + m) % m;
            dp[(base + a[i]) % m]++;
            ans += dp[base];
        }
        out << ans << endl;
    }
};

int main() {
    // Set up input and output streams
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    TaskD solver;
    // Solve the problem for the first test case
    solver.solve(1, cin, cout);
    return 0;
}

