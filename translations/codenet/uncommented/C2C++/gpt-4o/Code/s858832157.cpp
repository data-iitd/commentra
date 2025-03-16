#include <iostream>

int main() {
    int i = 1, Input;
    while (true) {
        std::cin >> Input;
        if (Input == 0) {
            break;
        }
        std::cout << "Case " << i << ": " << Input << std::endl;
        i++;
    }
    return 0;
}

// <END-OF-CODE>
