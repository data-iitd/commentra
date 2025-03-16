
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long result = 0;
    for (int b = 0; b < 60; b++) {
        long long bs = 0;
        for (int i = 0; i < N; i++) {
            bs += (A[i] >> b) & 1;
        }
        long long contribution = bs * (N - bs) * (1LL << b);
        result = (result + contribution) % 1000000007;
    }
    cout << result << endl;
    return 0;
}

