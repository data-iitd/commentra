#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 0;

    for (int i = 1; i < n + 1; i++) {
        long long term = (long long)n / (long long)i;
        long long sum = term * (term + 1) / 2;
        ans += (long long)i * sum;
    }

    cout << ans << endl;
}

