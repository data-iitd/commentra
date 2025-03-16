#include <iostream>
#include <vector>
#include <cmath>

int main() {
    long x;
    std::cin >> x;
    std::vector<long> list;

    while (x > 0) {
        long r = x % 10;

        if (9 - r < r) {
            if (x / 10 == 0 && 9 - r == 0) {
                list.push_back(r);
            } else {
                list.push_back(9 - r);
            }
        } else {
            list.push_back(r);
        }

        x = x / 10;
    }

    int pow = 0;
    long newNumber = 0;

    for (int i = 0; i < list.size(); i++) {
        newNumber = newNumber + list[i] * static_cast<long>(std::pow(10, pow));
        pow++;
    }

    std::cout << newNumber << std::endl;

    return 0;
}
