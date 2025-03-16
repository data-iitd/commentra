
#include <iostream>

int min(int a, int b) {
    return a < b? a : b;
}

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::cout << min(n * a, b) << std::endl;

    return 0;
}
