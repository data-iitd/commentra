#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int l, r;
    std::cin >> l >> r;

    int curr = r;
    int s = 0;

    while (curr) {
        s += 1;
        curr /= 10;
    }

    int first = 10 * s;
    int second = first / 2;

    int ans = -1;

    for (int i : {l, r, first, second}) {
        if (i >= l && i <= r) {
            curr = i;
            std::string rev = "";
            for (char k : std::to_string(curr)) {
                rev += std::to_string(9 - (k - '0'));
            }
            ans = std::max(ans, std::stoi(rev) * curr);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

