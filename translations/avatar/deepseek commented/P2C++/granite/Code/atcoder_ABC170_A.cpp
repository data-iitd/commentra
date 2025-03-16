

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> a;
    int temp;
    while (std::cin >> temp) {
        a.push_back(temp);
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 0) {
            std::cout << i + 1 << std::endl;
            break;
        }
    }
    return 0;
}

