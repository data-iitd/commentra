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

    // Check if the sum of the elements in the list is divisible by the formula
    if (std::accumulate(a.begin(), a.end(), 0) % (n * (n + 1) / 2)) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    // Calculate the average of the elements in the list
    double k = static_cast<double>(std::accumulate(a.begin(), a.end(), 0)) / (n * (n + 1) / 2);

    // Add the first element to the end of the list for simplification
    a.push_back(a[0]);

    // Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
    bool valid = true;
    for (int i = 1; i <= n; ++i) {
        if ((k - a[i] + a[i - 1]) % n != 0 || (k - a[i] + a[i - 1]) / n < 0) {
            valid = false;
            break;
        }
    }

    // If all checks pass, print YES
    if (valid) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
