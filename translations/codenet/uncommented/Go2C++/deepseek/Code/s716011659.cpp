#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arrA(n);
    for (int i = 0; i < n; i++) {
        cin >> arrA[i];
    }

    vector<int> cumSumA(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cumSumA[i + 1] = cumSumA[i] + arrA[i];
    }

    long double ans = LLONG_MAX;
    for (int i = 1; i < n; i++) {
        long double current = abs(static_cast<long double>(cumSumA[n] - 2 * cumSumA[i]));
        if (current < ans) {
            ans = current;
        }
    }

    cout << static_cast<long long>(ans) << endl;

    return 0;
}

