#include <iostream>
#include <vector>
#include <cmath>

int main() {
    long long x;
    std::cin >> x;
    std::vector<long long> list;

    while (x > 0) {
        long long r = x % 10;
        if (9 - r < r) {
            if (x / 10 == 0 && 9 - r == 0) 
                list.push_back(r);
            else 
                list.push_back(9 - r);
        } else {
            list.push_back(r);
        }
        x = x / 10;
    }

    long long newNumber = 0;
    int pow = 0;
    for (int i = 0; i < list.size(); i++) {
        newNumber += list[i] * static_cast<long long>(pow(10, pow));
        pow++;
    }

    std::cout << newNumber << std::endl;
    return 0;
}

// <END-OF-CODE>
