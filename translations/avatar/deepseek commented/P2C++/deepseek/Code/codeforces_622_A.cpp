#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int l = 1;
    int r = n;

    while (l < r) {
        int mid = l + (r - l) / 2;
        double idxcnt = mid * (mid + 1) / 2;
        if (idxcnt < n) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    l -= 1;
    double idxcnt = l * (l + 1) / 2;

    cout << static_cast<int>(n - idxcnt) << endl;

    return 0;
}

