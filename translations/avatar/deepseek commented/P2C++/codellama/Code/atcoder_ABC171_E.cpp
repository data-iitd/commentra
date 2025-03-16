#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int total = accumulate(a.begin(), a.end(), 0, bit_xor<int>());

    vector<int> b(N);
    transform(a.begin(), a.end(), b.begin(), [total](int ai) { return ai ^ total; });

    for (int i = 0; i < N; i++) {
        cout << b[i] << " ";
    }

    return 0;
}

