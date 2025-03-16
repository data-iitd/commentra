
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
    }
    vector<int> S(N);
    partial_sum(A.begin(), A.end(), S.begin() + 1);
    int ans = 1 << 30;
    for (int k = 1; k <= N; k++) {
        int E = k * X + 2 * accumulate(S.begin() + max(0, N - 2 * k - 1), S.end(), 0);
        ans = min(ans, E);
    }
    cout << ans + N * X + 5 * S[N - 1] << endl;
    return 0;
}

