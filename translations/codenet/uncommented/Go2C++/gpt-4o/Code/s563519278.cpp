#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> v(N, 0);
    int a;

    for (int i = 1; i < N; i++) {
        std::cin >> a;
        v[a - 1]++;
    }

    for (const auto& e : v) {
        std::cout << e << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
