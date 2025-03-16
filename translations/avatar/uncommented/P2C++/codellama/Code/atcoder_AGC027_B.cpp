#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> S(N);
    partial_sum(A.begin(), A.end(), S.begin());
    int ans = numeric_limits<int>::max();
    for (int k = 1; k <= N / 2; k++) {
        int E = k * X + 2 * accumulate(S.begin() + N - 2 * k - 1, S.end(), 0, [](int a, int b) { return a + b; });
        ans = min(ans, E);
    }
    cout << ans + N * X + 5 * S[N - 1] << endl;
}