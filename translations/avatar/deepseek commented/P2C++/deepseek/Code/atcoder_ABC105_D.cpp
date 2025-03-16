#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric> // for std::accumulate

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long long> cum_remainders(N + 1);
    cum_remainders[0] = 0;
    for (int i = 0; i < N; ++i) {
        cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M;
    }

    unordered_map<int, int> remainder_counts;
    for (int i = 0; i <= N; ++i) {
        ++remainder_counts[cum_remainders[i]];
    }

    long long combinations = 0;
    for (const auto& pair : remainder_counts) {
        int count = pair.second;
        combinations += static_cast<long long>(count) * (count - 1) / 2;
    }

    cout << combinations << endl;

    return 0;
}
