#include <iostream>
#include <cmath>

int main() {
    int N;
    std::cin >> N;
    
    int i = 1;
    long long ans = 0;
    
    while (std::pow(10, i) <= N) {
        ans += (std::pow(10, i) - std::pow(10, i - 1));
        i += 2;
    }
    
    ans += std::max(0, N - std::pow(10, i - 1) + 1);
    
    std::cout << ans << std::endl;
    
    return 0;
}
