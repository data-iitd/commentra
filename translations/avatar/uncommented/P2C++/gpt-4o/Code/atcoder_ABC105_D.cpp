#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long long> cum_remainders(N + 1);
    cum_remainders[0] = 0;

    for (int i = 1; i <= N; ++i) {
        cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
    }

    unordered_map<long long, long long> remainder_counts;
    for (const auto& remainder : cum_remainders) {
        remainder_counts[remainder]++;
    }

    long long combinations = 0;
    for (const auto& count : remainder_counts) {
        combinations += count.second * (count.second - 1) / 2;
    }

    cout << combinations << endl;

    return 0;
}

// <END-OF-CODE>
