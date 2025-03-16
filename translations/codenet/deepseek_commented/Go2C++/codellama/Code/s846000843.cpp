
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> aa(n);
    for (int i = 0; i < n; i++) {
        cin >> aa[i];
    }

    vector<int> cumsum = CumSum(aa);

    //cout << cumsum << endl;

    int ans = 2020202020;
    for (int i = 1; i < cumsum.size() - 1; i++) {
        ans = min(ans, abs(cumsum[cumsum.size() - 1] - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    cout << ans << endl;

    return 0;
}

vector<int> CumSum(vector<int> nums) {
    vector<int> sums(1, 0);

    for (int i = 0; i < nums.size(); i++) {
        sums.push_back(sums[i] + nums[i]);
    }

    return sums;
}

int abs(int a) {
    if (a >= 0) {
        return a;
    } else {
        return -a;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

