#include <iostream>
#include <vector>
#include <sstream>
#include <set>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    
    std::vector<int> lista(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> lista[i];
    }
    
    std::set<int> setA(lista.begin(), lista.end());
    
    for (int k = 0; k < n; ++k) {
        if (setA.find(k + 1) != setA.end()) {
            std::cout << 1 << " ";
        } else {
            std::cout << 2 << " ";
        }
    }
    
    return 0;
}

// <END-OF-CODE>
