
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int maxn = 4010;
    int arr[3] = {a, b, c};
    int dp[maxn];
    for (int i = 0; i < n; i++) {
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = arr[i]; j < maxn; j++) {
            dp[j] = max(dp[j], dp[j - arr[i]] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
// END-OF-CODE