
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> cookies;
    for (int i = 0; i < 3; i++) {
        int cookie;
        std::cin >> cookie;
        cookies.push_back(cookie);
    }

    int leftOver = cookies[0] - cookies[2];
    int takahashi = std::max(0, leftOver);

    std::cout << takahashi << " " <<
              (takahashi > 0? std::to_string(cookies[1]) :
               std::to_string(std::max(0, cookies[1] - std::abs(leftOver)))) << std::endl;

    return 0;
}
