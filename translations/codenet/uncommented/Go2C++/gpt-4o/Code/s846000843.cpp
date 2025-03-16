#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>

using namespace std;

int Abs(int a) {
    return a >= 0 ? a : -a;
}

int Min(int a, int b) {
    return a < b ? a : b;
}

vector<int> CumSum(const vector<int>& nums) {
    vector<int> sums(nums.size() + 1, 0);
    for (size_t i = 0; i < nums.size(); i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    return sums;
}

int main() {
    int n;
    cin >> n;

    vector<int> aa(n);
    for (int i = 0; i < n; i++) {
        cin >> aa[i];
    }

    vector<int> cumsum = CumSum(aa);

    int ans = numeric_limits<int>::max();
    for (int i = 1; i < cumsum.size() - 1; i++) {
        ans = Min(ans, Abs(cumsum.back() - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
