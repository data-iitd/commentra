#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> logsLength(n);
        for (int i = 0; i < n; ++i) {
            cin >> logsLength[i];
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
        cout << min << endl;
    }

private:
    bool nei(int mid, const vector<int>& logsLength, int k) {
        for (int log : logsLength) {
            k -= (log + mid - 1) / mid - 1;
        }
        return k >= 0;
    }
};

int main() {
    Solution solution;
    solution.solve();
    return 0;
}

