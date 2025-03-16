#include <iostream>
#include <vector>
#include <cstdlib> // for abs

int main() {
    int n;
    std::cin >> n;
    std::vector<int> r(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> r[i];
    }
    
    int ans = abs(r[0]);
    for (int i = 1; i < n; ++i) {
        ans += abs(r[i] - r[i - 1]);
    }
    
    std::cout << ans << std::endl;
    return 0;
}

// <END-OF-CODE>
