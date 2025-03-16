#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Read input number of rows and columns
    int N, M;
    cin >> N >> M;

    // Initialize vector 'A' with given dimensions
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Calculate cumulative remainders
    vector<long long> cum_remainders(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
    }

    // Count the occurrences of each cumulative remainder
    unordered_map<long long, long long> remainder_counts;
    for (const auto& remainder : cum_remainders) {
        remainder_counts[remainder]++;
    }

    // Calculate the number of combinations of elements having the same remainder
    long long combinations = 0;
    for (const auto& entry : remainder_counts) {
        long long count = entry.second;
        combinations += count * (count - 1) / 2;
    }

    // Print the result
    cout << combinations << endl;

    return 0;
}
// <END-OF-CODE>
