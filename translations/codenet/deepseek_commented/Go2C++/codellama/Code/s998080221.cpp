
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, _;
    cin >> N >> _;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int maxProfit = 0;
    int maxCnt = 0;
    int maxA = A[N-1];
    for (int i = N - 2; i >= 0; i--) {
        int profit = max(0, maxA-A[i]);
        if (maxProfit < profit) {
            maxProfit = profit;
            maxCnt = 1;
        } else if (maxProfit == profit) {
            maxCnt++;
        }
        maxA = max(maxA, A[i]);
    }
    cout << maxCnt << endl;

    return 0;
}

