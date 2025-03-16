#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> array(3 * n);
    for (int i = 0; i < array.size(); i++) {
        std::cin >> array[i];
    }

    std::sort(array.begin(), array.end());

    int head = array.size() - 2;
    long long res = 0;

    for (int i = 0; i < n; i++) {
        res += array[head];
        head -= 2;
    }

    std::cout << res << std::endl;

    return 0;
}

