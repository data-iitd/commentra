#include <iostream>
#include <vector>

int main() {
    int inp;
    std::cin >> inp;
    std::vector<int> lista(inp);
    
    for (int i = 0; i < inp; ++i) {
        std::cin >> lista[i];
    }
    
    for (int i = 0; i < lista.size(); ++i) {
        if (i == 0) {
            std::cout << lista[i + 1] - lista[i] << " " << lista[lista.size() - 1] - lista[i] << std::endl;
            continue;
        } else if (i == lista.size() - 1) {
            std::cout << lista[lista.size() - 1] - lista[lista.size() - 2] << " " << lista[lista.size() - 1] - lista[0] << std::endl;
            continue;
        } else if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            std::cout << lista[i + 1] - lista[i] << " ";
        } else {
            std::cout << lista[i] - lista[i - 1] << " ";
        }
        
        if (lista[lista.size() - 1] - lista[i] > lista[i] - lista[0]) {
            std::cout << lista[lista.size() - 1] - lista[i] << std::endl;
        } else {
            std::cout << lista[i] - lista[0] << std::endl;
        }
    }
    
    return 0;
}

// <END-OF-CODE>
