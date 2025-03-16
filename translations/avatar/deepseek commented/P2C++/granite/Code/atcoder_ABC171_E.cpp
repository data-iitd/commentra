
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int total = accumulate(a, a + N, 0, bit_xor<int>());

    for (int i = 0; i < N; i++) {
        cout << (a[i] ^ total) << " ";
    }

    return 0;
}
