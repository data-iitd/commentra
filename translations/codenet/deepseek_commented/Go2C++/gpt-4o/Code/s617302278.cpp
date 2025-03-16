#include <iostream>
#include <vector>

int main() {
    int x;
    std::cin >> x;

    int i = 1;
    int sum = 0;
    while (true) {
        sum += i;
        if (sum >= x) {
            break;
        }
        i++;
    }
    std::cout << i << std::endl;

    return 0;
}

// <END-OF-CODE>
