#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> cum_remainders(N + 1);
    partial_sum(A.begin(), A.end(), cum_remainders.begin() + 1, [M](int a, int b) { return (a + b) % M; });
    map<int, int> remainder_counts;
    for (int i = 0; i < N + 1; i++) {
        remainder_counts[cum_remainders[i]]++;
    }
    long long combinations = 0;
    for (auto &[remainder, count] : remainder_counts) {
        combinations += count * (count - 1) / 2;
    }
    cout << combinations << endl;
    return 0;
}

