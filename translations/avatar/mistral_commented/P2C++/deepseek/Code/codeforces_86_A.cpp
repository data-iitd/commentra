#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int l, r;
    std::cin >> l >> r;

    int curr = r;
    int s = 0;
    int ans = -1;

    while (curr) {
        s += 1;
        int first = 10 * s;
        int second = first / 2;

        for (int i : {l, r, first, second}) {
            if (i >= l && i <= r) {
                curr = i;
                std::string rev = "";
                for (char c : std::to_string(curr)) {
                    rev = std::string(1, '9' - c) + rev;
                }
                ans = std::max(ans, std::stoi(rev) * curr);
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}

