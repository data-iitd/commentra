#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;
    long long onePrice = min({Q * 4, H * 2, S});
    if (static_cast<double>(onePrice) <= static_cast<double>(D) / 2) {
        cout << N * onePrice << endl;
    } else {
        cout << (N / 2) * D + (N % 2) * onePrice << endl;
    }
    return 0;
}

