
#include <iostream>

int main() {
    int age;
    std::cin >> age;

    if (age == 1) {
        std::cout << "Hello World" << std::endl;
    } else {
        int a, b;
        std::cin >> a >> b;
        std::cout << a + b << std::endl;
    }

    return 0;
}
// END-OF-CODE