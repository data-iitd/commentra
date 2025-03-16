
#include <iostream>
using namespace std;

int main() {
    int n;
    long ans = 0;
    cin >> n;

    for (int i = 1; i < n + 1; i++) {
        long term = n / i;
        long sum = term * (term + 1) / 2;
        ans += i * sum;
    }

    cout << ans << endl;
    return 0;
}

