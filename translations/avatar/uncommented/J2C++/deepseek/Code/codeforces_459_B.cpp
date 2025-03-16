#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric> // for std::gcd

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int min = A[0];
    int max = A[N - 1];
    long long mins = 0;
    long long maxs = 0;
    for (int value : A) {
        if (value == min) mins++;
        if (value == max) maxs++;
    }
    if (min == max) {
        cout << (max - min) << " " << mins * (mins - 1) / 2 << endl;
    } else {
        cout << (max - min) << " " << mins * maxs << endl;
    }
    return 0;
}

