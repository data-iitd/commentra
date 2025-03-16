
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TaskD {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            in >> a[i];
        }
        unordered_map<int, int> dp;
        int base = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            base = (base - a[i] % m + m) % m;
            dp[(base + a[i]) % m]++;
            ans += dp[base];
        }
        out << ans << endl;
    }
};

int main() {
    TaskD solver;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solver.solve(1, cin, cout);
    return 0;
}

