
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long ans = 0;

    for (int i = 1; i < n + 1; i++) {
        long term = (long) n / (long) i;
        long sum = term * (term + 1) / 2;
        ans += (long) i * sum;
    }

    cout << ans << endl;
    return 0;
}

