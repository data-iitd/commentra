#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> l(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> l[i];
    }
    
    int tmpSum = 0;
    int rs = 0;
    
    for (int i = 0; i < n; i++) {
        tmpSum += l[i];
        if (tmpSum <= x) {
            rs = i + 2;
        } else {
            break;
        }
    }
    
    std::cout << rs << std::endl;
    return 0;
}

// <END-OF-CODE>
