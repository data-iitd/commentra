#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    // Read the values of N and M from the standard input
    int N, M;
    cin >> N >> M;

    // Read the array A from the standard input
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Calculate the cumulative remainders of the array A modulo M
    // Include a 0 at the beginning to handle the case when the cumulative sum starts from 0
    vector<int> cum_remainders(N + 1);
    for (int i = 0; i < N; i++) {
        cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M;
    }

    // Count the occurrences of each remainder
    unordered_map<int, int> remainder_counts;
    for (int i = 0; i < N; i++) {
        remainder_counts[cum_remainders[i]]++;
    }

    // Initialize the number of combinations
    int combinations = 0;

    // Calculate the number of combinations where the difference between two remainders is a multiple of M
    for (auto count : remainder_counts) {
        combinations += count.second * (count.second - 1) / 2;
    }

    // Print the number of combinations
    cout << combinations << endl;

    return 0;
}

