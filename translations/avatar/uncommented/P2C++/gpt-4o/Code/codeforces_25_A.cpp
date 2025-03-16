#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> list(n);
    
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        list[i] = x % 2;
    }
    
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += list[i];
    }
    
    if (sum == 1) {
        for (int i = 0; i < n; ++i) {
            if (list[i] == 1) {
                std::cout << i + 1 << std::endl;
                break;
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (list[i] == 0) {
                std::cout << i + 1 << std::endl;
                break;
            }
        }
    }
    
    return 0;
}

// <END-OF-CODE>
