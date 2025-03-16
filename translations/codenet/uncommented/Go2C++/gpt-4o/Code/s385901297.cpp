#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> ns(4);
    
    for (int i = 0; i < 4; ++i) {
        std::cin >> ns[i];
    }

    std::sort(ns.begin(), ns.end());

    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
