#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> list1(a);
    std::vector<int> list2(b);

    for (int i = 0; i < a; i++) {
        std::cin >> list1[i];
    }
    for (int i = 0; i < b; i++) {
        std::cin >> list2[i];
    }

    for (int i = 0; i < n; i++) {
        if (std::find(list1.begin(), list1.end(), i + 1) != list1.end()) {
            std::cout << 1 << " ";
        } else {
            std::cout << 2 << " ";
        }
    }

    return 0;
}
