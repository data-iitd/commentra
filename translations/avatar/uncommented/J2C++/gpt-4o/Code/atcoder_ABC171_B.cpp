#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solve(istream &in, ostream &out) {
        int n, k;
        in >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += a[i];
        }
        out << ans << endl;
    }
};

int main() {
    Solution sol;
    sol.solve(cin, cout);
    return 0;
}

// <END-OF-CODE>
