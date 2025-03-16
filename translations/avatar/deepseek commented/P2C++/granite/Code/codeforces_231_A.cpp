
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    int c = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        int size;
        std::cin >> size;
        std::vector<int> l1(size);
        for (int j = 0; j < size; j++) {
            std::cin >> l1[j];
            sum += l1[j];
        }
        if (sum > 1) {
            c++;
        }
    }

    std::cout << c << std::endl;

    return 0;
}

