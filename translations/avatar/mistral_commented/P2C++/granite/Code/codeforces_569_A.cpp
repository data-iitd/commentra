
#include <iostream>

int main() {
    int t, s, q;
    std::cin >> t >> s >> q;

    int ans = 0;

    while (s < t) {
        s *= q;
        ans++;
    }

    std::cout << ans << std::endl;

    return 0;
}

