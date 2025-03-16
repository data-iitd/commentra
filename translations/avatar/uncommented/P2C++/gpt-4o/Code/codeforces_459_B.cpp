#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> l1(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> l1[i];
    }
    
    std::sort(l1.begin(), l1.end());
    int a = l1[n - 1];
    int b = l1[0];
    
    if (a == b) {
        std::cout << a - b << " " << (n * (n - 1)) / 2 << std::endl;
    } else {
        int ac = std::count(l1.begin(), l1.end(), a);
        int bc = std::count(l1.begin(), l1.end(), b);
        std::cout << a - b << " " << ac * bc << std::endl;
    }
    
    return 0;
}

// <END-OF-CODE>
