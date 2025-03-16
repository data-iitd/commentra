#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> numbers(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    
    std::sort(numbers.begin(), numbers.end());
    
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += numbers[i];
    }
    
    std::cout << sum << std::endl;
    return 0;
}

// <END-OF-CODE>
