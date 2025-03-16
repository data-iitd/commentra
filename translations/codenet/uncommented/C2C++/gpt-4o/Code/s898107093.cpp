#include <iostream>
#include <cstring>
#include <vector>

int main() {
    int n, taro = 0, hanako = 0;
    std::cin >> n;
    
    std::vector<std::string> t(n);
    std::vector<std::string> h(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
        std::cin >> h[i];
        
        if (t[i] < h[i]) {
            hanako += 3;
        } else if (t[i] > h[i]) {
            taro += 3;
        } else {
            taro += 1;
            hanako += 1;
        }
    }
    
    std::cout << taro << " " << hanako << std::endl;
    return 0;
}

// <END-OF-CODE>
