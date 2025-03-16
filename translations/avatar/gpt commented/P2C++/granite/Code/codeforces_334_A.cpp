
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int i = 1, j = n * n;

    while (i < j) {
        std::cout << i << " " << j << std::endl;
        i++;
        j--;
    }

    return 0;
}
// END-OF-CODE