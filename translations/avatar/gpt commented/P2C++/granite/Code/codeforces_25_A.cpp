
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> list(n);
    for (int i = 0; i < n; i++) {
        std::cin >> list[i];
        list[i] %= 2;
    }

    int count = std::count(list.begin(), list.end(), 1);
    if (count == 1) {
        int index = std::distance(list.begin(), std::find(list.begin(), list.end(), 1));
        std::cout << index + 1 << std::endl;
    } else {
        int index = std::distance(list.begin(), std::find(list.begin(), list.end(), 0));
        std::cout << index + 1 << std::endl;
    }

    return 0;
}
