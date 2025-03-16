#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n1, n2, n3, n4;
    std::cin >> n1 >> n2 >> n3 >> n4;

    std::vector<int> ns = {n1, n2, n3, n4};
    std::sort(ns.begin(), ns.end());

    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

