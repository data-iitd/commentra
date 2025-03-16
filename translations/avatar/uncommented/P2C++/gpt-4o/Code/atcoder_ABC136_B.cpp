#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N;
    cin >> N;
    int i = 1;
    long long ans = 0;

    while (pow(10, i) <= N) {
        ans += (pow(10, i) - pow(10, i - 1));
        i += 2;
    }
    ans += max(0LL, N - pow(10, i - 1) + 1);
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
