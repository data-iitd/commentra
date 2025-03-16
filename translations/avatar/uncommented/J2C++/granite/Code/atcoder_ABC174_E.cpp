
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> logsLength(n);
        for (int i = 0; i < n; ++i) {
            in >> logsLength[i];
        }
        int min = 1, max = 1e9 + 1000;
        while (min < max) {
            int mid = (min + max) / 2;
            if (nei(mid, logsLength, k)) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        out << min << endl;
    }

private:
    bool nei(int mid, vector<int>& logsLength, int k) {
        for (int log : logsLength) {
            k -= (log + mid - 1) / mid - 1;
        }
        return k >= 0;
    }
};

void solve(std::istream& in, std::ostream& out) {
    Solution solution;
    solution.solve(in, out);
}

int main() {
    solve(std::cin, std::cout);
    return 0;
}

