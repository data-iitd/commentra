#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    int id = 0;
    int l, r;
    std::cin >> l >> r;
    for (int i = 1; i < n; ++i) {
        int li, ri;
        std::cin >> li >> ri;
        if (li <= l && r <= ri) {
            id = i;
        } else if (li < l || r < ri) {
            id = n;
        }
        l = std::min(l, li);
        r = std::max(r, ri);
    }
    std::cout << (id == n ? -1 : id + 1) << std::endl;
    return 0;
}
