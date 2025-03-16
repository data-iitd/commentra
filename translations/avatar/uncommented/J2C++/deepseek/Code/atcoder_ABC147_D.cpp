#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;

int main() {
    auto startTime = chrono::high_resolution_clock::now();
    int n;
    cin >> n;
    const long div = pow(10, 9) + 7;
    vector<long> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    long ans = 0;
    for (int i = 0; i < 60; i++) {
        long a = 0;
        long count1 = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] >> i & 1) count1++;
        }
        a = a + count1 * (n - count1);
        for (int j = 0; j < i; j++) {
            a = (a << 1) % div;
        }
        ans += a;
        ans %= div;
    }
    cout << ans << endl;
    auto endTime = chrono::high_resolution_clock::now();
    // <END-OF-CODE>