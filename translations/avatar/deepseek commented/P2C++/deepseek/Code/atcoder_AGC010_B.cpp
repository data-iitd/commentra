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

    int sum_a = std::accumulate(a.begin(), a.end(), 0);
    int triangular_number = n * (n + 1) / 2;

    if (sum_a % triangular_number != 0) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    double k = static_cast<double>(sum_a) / triangular_number;
    a.push_back(a[0]); // Append the first element to the end to create a circular list

    bool valid = true;
    for (int i = 1; i < n; ++i) {
        if ((k - a[i] + a[i - 1]) % n != 0 || (k - a[i] + a[i - 1]) / n < 0) {
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
