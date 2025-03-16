#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<pair<int, int>> dp;
    dp.push_back(make_pair(A[0], 0));
    for (int i = 1; i < N; i++) {
        if (A[i] <= dp.back().first) {
            dp.push_back(make_pair(A[i], 0));
        } else {
            for (int j = dp.size() - 1; j >= 0; j--) {
                if (dp[j].second < 1) {
                    dp.push_back(make_pair(A[i], 0));
                    break;
                }
                if (dp[j].first < A[i]) {
                    dp.push_back(make_pair(A[i], 0));
                    break;
                }
                if (dp[j].first == A[i]) {
                    dp[j].second++;
                    break;
                }
                if (dp[j].first > A[i]) {
                    dp.push_back(make_pair(A[i], 0));
                    break;
                }
            }
        }
    }
    int K;
    cin >> K;
    int ans = 0;
    for (int i = 0; i < dp.size(); i++) {
        if (dp[i].second >= K - 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}



