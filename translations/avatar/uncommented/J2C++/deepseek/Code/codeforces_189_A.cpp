#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> arr = {a, b, c};
    vector<int> dp(4010, INT_MIN);
    dp[0] = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = arr[i]; j < dp.size(); j++) {
            dp[j] = max(dp[j], dp[j - arr[i]] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}

