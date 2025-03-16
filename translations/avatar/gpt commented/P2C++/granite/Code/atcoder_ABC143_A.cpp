
#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;
    int ans = A - 2 * B;
    if (ans < 0) {
        ans = 0;
    }
    std::cout << ans << std::endl;
    return 0;
}
// END-OF-CODE