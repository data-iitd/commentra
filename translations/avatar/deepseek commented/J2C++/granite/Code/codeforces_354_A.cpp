
#include <iostream> // Including the necessary libraries
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, L, R, QL, QR; // Declaring variables for input
    cin >> N >> L >> R >> QL >> QR; // Reading the input values

    vector<int> W(N); // Vector to store the weights of items
    vector<int> sum(N + 1); // Vector to store cumulative sums of weights

    // Reading the weights and calculating cumulative sums
    for (int n = 0; n < N; n++) {
        cin >> W[n];
        sum[n + 1] = sum[n] + W[n];
    }

    // Initializing the minimum cost to a very large value
    long long min = LLONG_MAX;

    // Iterating over possible positions for the rightmost item
    for (int firstR = 0; firstR <= N; firstR++) {
        int lCount = firstR; // Number of items on the left
        int rCount = N - lCount; // Number of items on the right

        // Calculating the cost for the current position of the rightmost item
        long long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R;

        // Calculating the additional costs for unbalanced counts
        int llCount = max(0, lCount - rCount - 1);
        int rrCount = max(0, rCount - lCount - 1);
        cand += llCount * QL;
        cand += rrCount * QR;

        // Updating the minimum cost found so far
        min = min(cand, min);
    }

    // Printing the minimum cost
    cout << min << endl; // Printing the minimum cost

    return 0;
}

