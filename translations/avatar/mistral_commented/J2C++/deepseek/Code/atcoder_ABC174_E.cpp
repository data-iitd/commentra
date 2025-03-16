#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

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

        int minDay = 1, maxDay = 1e9 + 1000;

        while (minDay < maxDay) {
            int mid = (minDay + maxDay) / 2;
            if (nei(mid, logsLength, k)) {
                maxDay = mid;
            } else {
                minDay = mid + 1;
            }
        }

        cout << minDay << endl;
    }

private:
    bool nei(int mid, const vector<int>& logsLength, int k) {
        int daysNeeded = 0;

        for (int log : logsLength) {
            daysNeeded += (log + mid - 1) / mid;
            k -= daysNeeded;
            if (k < 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    solution.solve();
    return 0;
}

