#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

long long combi(int n, int k) {
    long long min = (k - 1LL) * k / 2;
    long long max = (2LL * n - k + 1) * k / 2;
    return max - min + 1;
}

long long pow64(long long base, unsigned int exponent) {
    long long answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;

    const long long MOD = pow64(10, 9) + 7;
    long long total = 0;

    for (int i = k; i <= n + 1; i++) {
        total += combi(n, i);
        total %= MOD;
    }

    cout << total << endl;
    return 0;
}

// <END-OF-CODE>
