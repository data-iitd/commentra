
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int gcd = accumulate(A.begin(), A.end(), 0, [](int a, int b) {
        return gcd(a, b);
    });
    cout << gcd << endl;
    return 0;
}

