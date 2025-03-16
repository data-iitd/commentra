#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    // Read input number of rows and columns
    int N, M;
    cin >> N >> M;

    // Initialize vector 'A' with given dimensions and data type
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Calculate cumulative remainders by performing modulo M operation on the sum of previous remainders and current element
    vector<int> cum_remainders(N + 1);
    partial_sum(A.begin(), A.end(), cum_remainders.begin() + 1, [M](int a, int b) { return (a + b) % M; });

    // Count the occurrences of each cumulative remainder
    vector<int> remainder_counts(M);
    for (int i = 0; i < N + 1; i++) {
        remainder_counts[cum_remainders[i]]++;
    }

    // Calculate the number of combinations of elements having the same remainder
    int combinations = 0;
    for (int count : remainder_counts) {
        combinations += count * (count - 1) / 2;
    }

    // Print the result
    cout << combinations << endl;

    return 0;
}

