#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

int main() {
    // Read the values of N and M from standard input
    int N, M;
    cin >> N >> M;

    // Read the array A from standard input and convert it to a vector of int64 type
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Calculate cumulative remainders of the array A when divided by M
    // Start with a 0 to handle the case of subarrays starting from index 0
    vector<int64_t> cum_remainders(N + 1);
    partial_sum(A.begin(), A.end(), cum_remainders.begin() + 1, [M](int64_t a, int64_t b) { return (a + b) % M; });

    // Count the occurrences of each remainder using map
    map<int64_t, int> remainder_counts;
    for (int64_t remainder : cum_remainders) {
        remainder_counts[remainder]++;
    }

    // Initialize a variable to count the number of valid combinations
    int combinations = 0;

    // Calculate the number of combinations of indices that have the same remainder
    for (auto [remainder, count] : remainder_counts) {
        combinations += count * (count - 1) / 2;  // Combinations of 2 from count
    }

    // Output the total number of combinations found
    cout << combinations << endl;

    return 0;
}

