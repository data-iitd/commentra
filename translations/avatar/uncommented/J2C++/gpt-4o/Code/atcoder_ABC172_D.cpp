#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        ans += i * (n / i) * ((n / i) + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
