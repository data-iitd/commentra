#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Read the values of N and M from the standard input
    int N, M;
    cin >> N >> M;

    // Read the array A from the standard input
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Calculate the cumulative remainders of the array A modulo M
    vector<long long> cum_remainders(N + 1);
    cum_remainders[0] = 0; // Include a 0 at the beginning
    for (int i = 1; i <= N; ++i) {
        cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
    }

    // Count the occurrences of each remainder
    unordered_map<long long, long long> remainder_counts;
    for (const auto& remainder : cum_remainders) {
        remainder_counts[remainder]++;
    }

    // Initialize the number of combinations
    long long combinations = 0;

    // Calculate the number of combinations where the difference between two remainders is a multiple of M
    for (const auto& count : remainder_counts) {
        combinations += count.second * (count.second - 1) / 2;
    }

    // Print the number of combinations
    cout << combinations << endl;

    return 0;
}

// <END-OF-CODE>
