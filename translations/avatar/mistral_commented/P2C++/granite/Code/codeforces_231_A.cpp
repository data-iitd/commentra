
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    int c = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            int num;
            std::cin >> num;
            sum += num;
        }
        if (sum > 1) {
            c++;
        }
    }

    std::cout << c << std::endl;

    return 0;
}

