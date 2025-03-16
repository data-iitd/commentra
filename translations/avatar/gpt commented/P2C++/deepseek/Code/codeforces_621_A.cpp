#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> lst(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> lst[i];
    }

    std::sort(lst.begin(), lst.end());
    std::reverse(lst.begin(), lst.end());

    int od = 0;
    for (int i : lst) {
        if (i & 1) {
            ++od;
        }
    }

    int sum = 0;
    bool ok = false;

    for (int i = 0; i < n; ++i) {
        if (lst[i] % 2 == 0) {
            sum += lst[i];
        } else {
            if (ok || od > 1) {
                sum += lst[i];
                --od;
                ok = !ok;
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
