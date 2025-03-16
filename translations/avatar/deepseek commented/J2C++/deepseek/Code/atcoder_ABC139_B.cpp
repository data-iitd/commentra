#include <iostream>
#include <cmath>

int main() {
    int A, B;
    std::cin >> A >> B;

    int result = (B - 1) / (A - 1);
    int remainder = (B - 1) % (A - 1);

    if (remainder != 0) {
        result += 1;
    }

    std::cout << result << std::endl;

    return 0;
}
