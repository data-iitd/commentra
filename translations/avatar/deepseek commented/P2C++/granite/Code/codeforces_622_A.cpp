

#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    int l = 1;
    int r = n;

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
    int idxcnt = l * (l + 1) / 2;

    std::cout << int(n - idxcnt) << std::endl;

    return 0;
}

