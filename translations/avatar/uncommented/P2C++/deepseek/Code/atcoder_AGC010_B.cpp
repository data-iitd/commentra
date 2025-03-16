#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int total_sum = std::accumulate(a.begin(), a.end(), 0);
    if (total_sum % (n * (n + 1) / 2)) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    double k = static_cast<double>(total_sum) / (n * (n + 1) / 2);
    a.push_back(a[0]);
    bool valid = true;

    for (int i = 1; i < n; ++i) {
        int current = (k - a[i] + a[i - 1]) % n;
        if (current < 0 || (k - a[i] + a[i - 1]) / n >= 0) {
            valid = false;
            break;
        }
    }

    if (valid) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
