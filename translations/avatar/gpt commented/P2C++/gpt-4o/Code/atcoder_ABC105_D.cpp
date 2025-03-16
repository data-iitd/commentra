#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Read the values of N and M from standard input
    int N, M;
    cin >> N >> M;

    // Read the array A from standard input
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Calculate cumulative remainders of the array A when divided by M
    vector<long long> cum_remainders(N + 1);
    cum_remainders[0] = 0; // Start with a 0 to handle the case of subarrays starting from index 0
    for (int i = 1; i <= N; ++i) {
        cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
    }

    // Count the occurrences of each remainder using unordered_map
    unordered_map<long long, long long> remainder_counts;
    for (const auto& remainder : cum_remainders) {
        remainder_counts[remainder]++;
    }

    // Initialize a variable to count the number of valid combinations
    long long combinations = 0;

    // Calculate the number of combinations of indices that have the same remainder
    for (const auto& pair : remainder_counts) {
        long long count = pair.second;
        combinations += count * (count - 1) / 2; // Combinations of 2 from count
    }

    // Output the total number of combinations found
    cout << combinations << endl;

    return 0;
}

// <END-OF-CODE>
