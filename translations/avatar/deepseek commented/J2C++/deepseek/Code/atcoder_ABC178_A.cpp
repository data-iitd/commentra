#include <iostream>
#include <string>

int main() {
    int x;
    std::cin >> x;
    bool bool_val = x == 1 ? true : false;
    int result = !bool_val ? 1 : 0;
    std::cout << result << std::endl;
    return 0;
}

