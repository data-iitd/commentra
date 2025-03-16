#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    // Define input variables
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Create a new list S by applying the accumulate function to the list A
    vector<int> S(N);
    partial_sum(A.begin(), A.end(), S.begin());

    // Initialize a variable ans with a large value
    int ans = INT_MAX;

    // Iterate through each element s in the list S
    for (int k = 1; k <= N; k++) {
        // Calculate the energy consumption E for the current index k
        int E = k * X + 2 * accumulate(S.begin() + N - 2 * k - 1, S.begin() + N, 0, plus<int>());

        // Update the minimum energy consumption ans if the current energy consumption E is smaller
        ans = min(ans, E);
    }

    // Print the result
    cout << ans + N * X + 5 * S[N - 1] << endl;

    return 0;
}

