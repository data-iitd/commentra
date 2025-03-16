#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

int64_t max(int64_t x, int64_t y) {
    return x > y ? x : y;
}

int64_t min(int64_t x, int64_t y) {
    return x < y ? x : y;
}

int64_t divUp(int64_t x, int64_t y) {
    return (x + y - 1) / y;
}

void solve() {
    int64_t N;
    cin >> N;
    vector<int64_t> T(N), A(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> A[i];
    }
    int64_t t = T[0], a = A[0];
    for (int i = 1; i < N; i++) {
        int64_t r = max(divUp(t, T[i]), divUp(a, A[i]));
        t = T[i] * r;
        a = A[i] * r;
    }
    cout << t + a << endl;
}

int main() {
    solve();
    return 0;
}
