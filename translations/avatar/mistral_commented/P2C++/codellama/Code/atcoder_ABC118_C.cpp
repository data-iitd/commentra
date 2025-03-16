#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int gcd = accumulate(A.begin(), A.end(), 0, [](int a, int b) {
        return gcd(b, a % b);
    });

    cout << gcd << endl;

    return 0;
}

