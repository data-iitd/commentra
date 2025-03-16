#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

int main() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int ans = 0;
    int i = 0, j = 0;
    while (j < A.size()) {
        if (x >= A[i]) {
            ans++;
            x -= A[i];
            i++;
        } else {
            j++;
        }
    }

    if (x > 0 && A.size() == ans) {
        ans--;
    }

    std::cout << ans << std::endl;

    return 0;
}
// <END-OF-CODE>
