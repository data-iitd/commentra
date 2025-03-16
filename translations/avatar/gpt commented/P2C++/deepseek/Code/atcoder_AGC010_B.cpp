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

    // Calculate the sum of the first n natural numbers
    int sum_n = n * (n + 1) / 2;

    // Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
    if (std::accumulate(a.begin(), a.end(), 0) % sum_n) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    // Calculate the average value 'k' that each element should contribute
    double k = static_cast<double>(std::accumulate(a.begin(), a.end(), 0)) / sum_n;

    // Append the first element of 'a' to the end of the list to facilitate circular calculations
    a.push_back(a[0]);

    // Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
    int adjusted_sum = 0;
    for (int i = 1; i <= n; ++i) {
        int adjusted_value = (k - a[i - 1] + a[i]) % n;
        if (adjusted_value < 0 || (k - a[i - 1] + a[i]) / n < 0) {
            std::cout << "NO" << std::endl;
            return 0;
        }
        adjusted_sum += adjusted_value;
    }

    // If both conditions are satisfied, print "YES"
    if (adjusted_sum == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
