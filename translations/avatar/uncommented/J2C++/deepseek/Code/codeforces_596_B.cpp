#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    long long answer = std::abs(arr[0]);
    for (int i = 1; i < n; i++) {
        answer += std::abs(arr[i] - arr[i - 1]);
    }
    std::cout << answer << std::endl;
    return 0;
}

