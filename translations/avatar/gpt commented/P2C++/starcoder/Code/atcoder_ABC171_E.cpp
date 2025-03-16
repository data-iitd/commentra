#include <iostream>
#include <vector>
#include <functional>
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
    for (int ai : a) {
        cout << ai ^ total << " ";
    }
    cout << "