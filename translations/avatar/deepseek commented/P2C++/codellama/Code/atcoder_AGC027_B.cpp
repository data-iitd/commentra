#include <bits/stdc++.h>
using namespace std;

int main() {
    // Step 1: Reading Input
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Step 2: Accumulating Sums
    vector<int> S(N);
    partial_sum(A.begin(), A.end(), S.begin());

    // Step 3: Initializing Answer
    double ans = numeric_limits<double>::infinity();

    // Step 4: Calculating Energy
    for (int k = 1; k <= N; k++) {
        double E = k * X + 2 * accumulate(S.begin() + N - 2 * k - 1, S.begin() + N - k, 0, plus<int>());
        ans = min(ans, E);
    }

    // Step 5: Final Calculation
    cout << fixed << setprecision(10) << ans + N * X + 5 * S[N - 1] << endl;

    return 0;
}

