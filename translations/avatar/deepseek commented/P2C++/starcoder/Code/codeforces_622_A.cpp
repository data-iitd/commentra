
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        int idxcnt = mid * (mid + 1) / 2;
        if (idxcnt < n) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    l -= 1;
    idxcnt = l * (l + 1) / 2;
    cout << n - idxcnt << endl;
    return 0;
}

