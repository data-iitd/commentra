
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    int q = n / m;
    int r = n % m;

    std::vector<int> a(m, q);
    for (int i = 0; i < r; i++) {
        a[i]++;
    }

    for (int i = 0; i < m; i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}
