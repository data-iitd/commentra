#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<double> arr(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    std::vector<double> fractionalParts;
    for (double x : arr) {
        double fractionalPart = x - static_cast<int>(x);
        if (fractionalPart != 0) {
            fractionalParts.push_back(fractionalPart);
        }
    }
    
    std::sort(fractionalParts.begin(), fractionalParts.end());
    int o = 2 * n - fractionalParts.size();
    double arr_sum = std::accumulate(fractionalParts.begin(), fractionalParts.end(), 0.0);
    int res = static_cast<int>(2e9);
    
    for (int i = 0; i <= n; ++i) {
        if (i + o >= n) {
            res = std::min(res, static_cast<int>(std::abs(i - arr_sum)));
        }
    }
    
    std::cout << std::fixed << std::setprecision(3) << res << std::endl;
    return 0;
}

// <END-OF-CODE>
