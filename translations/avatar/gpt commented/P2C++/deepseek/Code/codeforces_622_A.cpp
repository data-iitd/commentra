#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long l = 1, r = n;

    while (l < r) {
        long long mid = l + (r - l) / 2;
        long long idxcnt = mid * (mid + 1) / 2;

        if (idxcnt < n) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    l -= 1;
    long long idxcnt = l * (l + 1) / 2;
    cout << n - idxcnt << endl;

    return 0;
}

