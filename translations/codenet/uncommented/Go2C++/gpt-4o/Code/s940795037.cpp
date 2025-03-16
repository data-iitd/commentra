#include <iostream>
#include <vector>
#include <iomanip>

class Scanner {
public:
    Scanner() {
        std::cin.tie(nullptr);
        std::ios::sync_with_stdio(false);
    }

    int NextInt() {
        int x;
        std::cin >> x;
        return x;
    }
};

int main() {
    Scanner sc;

    int n = sc.NextInt();
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        ans += 1.0 / sc.NextInt();
    }
    std::cout << std::fixed << std::setprecision(10) << 1.0 / ans << "\n";

    return 0;
}

// <END-OF-CODE>
