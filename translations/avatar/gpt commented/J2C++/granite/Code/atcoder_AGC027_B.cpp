
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Define a constant for infinity, used for comparison
    int INF = INT_MAX;

    // Read the number of elements N and the multiplier X
    int N;
    long long X;
    cin >> N >> X;

    // Initialize a vector to store the elements and a prefix sum vector
    vector<long long> x(N);
    vector<long long> xsum(N + 1);

    // Read the elements into the vector and compute the prefix sums
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        xsum[i + 1] = xsum[i] + x[i];
    }

    // Initialize the answer with the cost of processing all elements with the base cost
    long long ans = X * N + 5 * xsum[N];

    // Iterate through possible splits of the vector
    for (int i = 1; i < N; i++) {
        // Calculate the cost for the current split
        long long cost = X * i + 5 * (xsum[N] - xsum[N - i]);

        // Incrementally add costs based on the current split
        for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) {
            // If the current cost exceeds the best answer found, break out of the loop
            if (cost > ans) {
                break;
            }
            // Update the cost based on the prefix sums
            cost += j * (xsum[k] - xsum[max(k - i, 0)]);
        }
        // Update the answer with the minimum cost found
        ans = min(ans, cost);
    }

    // Output the final answer, which includes the base cost
    cout << ans + N * X << endl;

    return 0;
}

