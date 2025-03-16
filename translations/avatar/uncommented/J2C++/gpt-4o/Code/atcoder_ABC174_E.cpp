#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

class Solution {
public:
    void solve(istream &in, ostream &out) {
        int n, k;
        in >> n >> k;
        vector<int> logsLength(n);
        for (int i = 0; i < n; ++i) {
            in >> logsLength[i];
        }
        
        int min = 1, max = (int)1e9 + 1000;
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
    bool nei(int mid, const vector<int> &logsLength, int k) {
        for (int log : logsLength) {
            k -= (log + mid - 1) / mid - 1;
        }
        return k >= 0;
    }
};

int main() {
    Solution sol;
    sol.solve(cin, cout);
    return 0;
}

// <END-OF-CODE>
