#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric> // for std::accumulate

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

    int mins = 0, maxs = 0;
    for (int value : A) {
        if (value == min) {
            ++mins;
        }
        if (value == max) {
            ++maxs;
        }
    }

    if (min == max) {
        long long result = (max - min) + 1;
        result *= mins;
        result -= mins * (mins - 1) / 2;
        cout << result << endl;
    } else {
        long long result = (max - min);
        result *= mins;
        result *= maxs;
        cout << result << endl;
    }

    return 0;
}
