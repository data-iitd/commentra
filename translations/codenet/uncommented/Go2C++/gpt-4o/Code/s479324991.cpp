#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    std::vector<double> arr(n);
    
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        arr[i] = static_cast<double>(temp);
    }
    
    std::sort(arr.begin(), arr.end());
    double prev = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        prev = (prev + arr[i]) / 2;
    }

    std::cout << std::fixed << std::setprecision(6) << prev << std::endl;
    return 0;
}

// <END-OF-CODE>
