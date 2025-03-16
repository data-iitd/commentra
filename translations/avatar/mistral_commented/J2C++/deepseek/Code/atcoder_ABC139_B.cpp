#include <iostream>
#include <cmath>

int main() {
    int A, B;
    std::cin >> A >> B;

    int result = (B - 1) / (A - 1);
    int amari = (B - 1) % (A - 1);

    if (amari != 0) {
        result += 1;
    }

    std::cout << result << std::endl;

    return 0;
}
