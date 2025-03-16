
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> S(N);
    partial_sum(A.begin(), A.end(), S.begin());
    int ans = 1e9;
    for (int k = 1; k <= N / 3; k++) {
        int E = k * X + 2 * accumulate(S.begin() + N - 2 * k - 1, S.end(), 0) / k;
        ans = min(ans, E);
    }
    cout << ans + N * X + 5 * S[N - 1] << endl;
    return 0;
}

