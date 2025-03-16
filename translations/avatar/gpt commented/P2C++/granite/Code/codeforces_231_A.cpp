
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    int c = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        int x;
        while (std::cin >> x) {
            sum += x;
        }
        if (sum > 1) {
            c++;
        }
    }

    std::cout << c << std::endl;

    return 0;
}

