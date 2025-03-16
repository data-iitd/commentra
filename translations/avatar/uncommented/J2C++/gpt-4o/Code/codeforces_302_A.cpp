#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::string res;
    int o = 0, e = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            ++o;
        } else {
            ++e;
        }
    }

    for (int i = 0; i < k; i++) {
        int l, r;
        std::cin >> l >> r;
        if ((r - l + 1) % 2 == 1) {
            res += "0\n";
        } else {
            if ((r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e) {
                res += "1\n";
            } else {
                res += "0\n";
            }
        }
    }

    std::cout << res;
    return 0;
}

// <END-OF-CODE>
