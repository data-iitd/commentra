
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int i = n; i > 0; --i) {
        if (n % i == 0) {
            n = i;
            std::cout << i <<'';
        }
    }

    return 0;
}
// END-OF-CODE