#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> data(n);
    
    for(int i = 0; i < n; i++) {
        std::cin >> data[i];
    }
    
    int max = 0, index = -1;
    for(int i = 0; i < n; i++) {
        if(data[i] > max) {
            max = data[i];
            index = i;
        }
    }
    
    int a = 0;
    for(int i = 0; i < n; i++) {
        if(i != index) {
            a += data[i];
        }
    }
    
    if(a > max) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}

// <END-OF-CODE>
