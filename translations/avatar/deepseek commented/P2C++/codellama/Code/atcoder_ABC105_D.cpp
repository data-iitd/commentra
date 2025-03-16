#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

int main() {
    // Read the values of N and M from the standard input
    int N, M;
    cin >> N >> M;

    // Read the array A from the standard input
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Calculate the cumulative remainders of the array A modulo M
    // Include a 0 at the beginning to handle the case when the cumulative sum starts from 0
    vector<int> cum_remainders(N + 1);
    partial_sum(A.begin(), A.end(), cum_remainders.begin() + 1, [M](int a, int b) { return (a + b) % M; });

    // Count the occurrences of each remainder
    map<int, int> remainder_counts;
    for (int remainder : cum_remainders) {
        ++remainder_counts[remainder];
    }

    // Initialize the number of combinations
    int combinations = 0;

    // Calculate the number of combinations where the difference between two remainders is a multiple of M
    for (const auto& [remainder, count] : remainder_counts) {
        combinations += count * (count - 1) / 2;
    }

    // Print the number of combinations
    cout << combinations << endl;

    return 0;
}

