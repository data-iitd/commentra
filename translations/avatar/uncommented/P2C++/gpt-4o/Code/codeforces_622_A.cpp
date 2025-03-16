#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int l = 1, r = n;

    while (l < r) {
        int mid = l + (r - l) / 2;
        long long idxcnt = mid * (mid + 1) / 2; // Use long long to avoid overflow
        if (idxcnt < n) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    l -= 1;
    long long idxcnt = l * (l + 1) / 2; // Use long long to avoid overflow
    cout << n - idxcnt << endl;

    return 0;
}

// <END-OF-CODE>
