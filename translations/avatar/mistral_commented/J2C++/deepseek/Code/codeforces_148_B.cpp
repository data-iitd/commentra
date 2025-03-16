#include <iostream>

int main() {
    double VP, VD, T, F, C;
    std::cin >> VP >> VD >> T >> F >> C;

    if (VD <= VP) {
        std::cout << "0" << std::endl;
        return 0;
    }

    int answer = 0;
    double start = T;

    while (true) {
        double x = start * VP / (VD - VP);

        if ((start + x) * VP >= C) {
            break;
        }

        start += 2 * x + F;
        answer++;
    }

    std::cout << answer << std::endl;
    return 0;
}

