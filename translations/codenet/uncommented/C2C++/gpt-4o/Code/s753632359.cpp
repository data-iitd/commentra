#include <iostream>

int main() {
    int N, D; // N, D are integers between 1 and 20
    int ans, rem;

    std::cin >> N >> D;

    ans = N / (D * 2 + 1);
    rem = N % (D * 2 + 1);

    if (rem != 0) {
        ans = ans + 1;
    }

    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
