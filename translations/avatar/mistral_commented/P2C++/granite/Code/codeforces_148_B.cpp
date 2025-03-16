

#include <iostream>

int main() {
    int princess, dragon, t, f, c;
    std::cin >> princess >> dragon >> t >> f >> c;

    if (dragon <= princess) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int result = 0;
    int position = t * princess;

    while (position < c) {
        result += 1;
        position += princess * position / dragon;
        position += princess * f;
        position += princess * position / (dragon - princess);
    }

    std::cout << result << std::endl;

    return 0;
}

