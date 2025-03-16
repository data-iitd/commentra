#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    // Read input values: N (number of elements), X (a constant), and A (the list of integers)
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Calculate the cumulative sum of the list A
    vector<int> S(N);
    partial_sum(A.begin(), A.end(), S.begin());

    // Initialize the answer to a very large number (infinity)
    int ans = numeric_limits<int>::max();

    // Iterate through the cumulative sums with an index starting from 1
    for (int k = 1; k <= N; k++) {
        // Calculate the expression E based on the current index k and the cumulative sums
        int E = k * X + 2 * accumulate(S.begin() + N - 2 * k - 1, S.begin() + N, 0, plus<int>());

        // Update the answer with the minimum value found so far
        ans = min(ans, E);
    }

    // Print the final result, which includes the minimum value found, adjusted by N * X and 5 times the last cumulative sum
    cout << ans + N * X + 5 * S[N - 1] << endl;

    return 0;
}

