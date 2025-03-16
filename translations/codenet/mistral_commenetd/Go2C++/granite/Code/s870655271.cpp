
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int ans = 0;
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    cout << ans << endl;

    return 0;
}

