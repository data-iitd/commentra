#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<long> arr(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    long answer = std::abs(arr[0]);
    for (int i = 1; i < n; i++) {
        answer += std::abs(arr[i] - arr[i - 1]);
    }
    
    std::cout << answer << std::endl;
    return 0;
}

// <END-OF-CODE>
