
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long total = 0;
    for (int i = k; i <= n + 1; i++) {
        total += combi(n, i);
        total = total % (pow(10, 9) + 7);
    }
    cout << total << endl;

    return 0;
}

long long combi(int n, int k) {
    long long min = (k - 1) * k / 2;
    long long max = (2 * n - k + 1) * k / 2;
    return max - min + 1;
}

