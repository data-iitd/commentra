#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> list(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> list[i];
    }
    
    std::sort(list.begin(), list.end());
    
    int c = 1;
    for (int i = 0; i < n; i++) {
        if (list[i] >= c) {
            c++;
        }
    }
    
    std::cout << c << '\n';
    return 0;
}

// <END-OF-CODE>
