#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> round_complexity(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> round_complexity[i];
    }
    
    std::vector<int> george_complexity(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> george_complexity[i];
    }
    
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        if (round_complexity[i] <= george_complexity[j]) {
            ++i;
        }
        ++j;
    }
    
    std::cout << n - i << std::endl;
    
    return 0;
}
