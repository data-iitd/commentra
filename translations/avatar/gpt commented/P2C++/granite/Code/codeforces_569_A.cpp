
#include <iostream>

int main() {
    int t, s, q;
    std::cin >> t >> s >> q;

    int ans = 0;
    while (s < t) {
        s *= q;
        ans += 1;
    }

    std::cout << ans << std::endl;

    return 0;
}
// END-OF-CODE