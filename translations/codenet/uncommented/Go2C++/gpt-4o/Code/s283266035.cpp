#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i * i < n; i++) {
        if (n % i == 0 && n / (n / i - 1) == i) {
            ans += n / i - 1;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

// <END-OF-CODE>
