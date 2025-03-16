
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> a;
    int tmp;
    while (std::cin >> tmp) {
        a.push_back(tmp);
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) {
            std::cout << i + 1 << std::endl;
            break;
        }
    }
    return 0;
}

