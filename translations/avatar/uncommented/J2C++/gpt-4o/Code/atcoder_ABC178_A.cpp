#include <iostream>

int main() {
    int x;
    std::cin >> x;
    bool boolValue = (x == 1);
    int result = !boolValue ? 1 : 0;
    std::cout << result << std::endl;
    return 0;
}

// <END-OF-CODE>
