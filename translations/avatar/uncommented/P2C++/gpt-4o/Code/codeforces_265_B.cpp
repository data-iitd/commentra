#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> l;
    
    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        l.push_back(value);
    }
    
    long long ans = n - 1;
    int last = 0;
    
    for (int i = 0; i < n; i++) {
        ans += std::abs(last - l[i]) + 1;
        last = l[i];
    }
    
    std::cout << ans << std::endl;
    return 0;
}

// <END-OF-CODE>
