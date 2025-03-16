
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int min = a < b? a : b;
    int half_diff = (a - b) / 2;

    std::cout << min << " " << half_diff << std::endl;

    return 0;
}
// END-OF-CODE