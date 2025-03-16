#include <iostream>
#include <string>

int main() {
    int h, a;
    std::cin >> h >> a;

    int num = 0;

    while (h > 0) {
        h -= a;
        num++;
    }

    std::cout << num << std::endl;

    return 0;
}
