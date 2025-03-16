#include <iostream>

int main() {
    int T, S, q;
    std::cin >> T >> S >> q;

    int answer = 0;
    double previous = S;

    while (previous < T) {
        answer++;
        previous *= q;
    }

    std::cout << answer << std::endl;

    return 0;
}
