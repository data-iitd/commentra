#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::vector<std::vector<int>> c(3, std::vector<int>(3));
    std::vector<int> a(3), b(3);

    // Read values into the 3x3 array `c`
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> c[i][j];
        }
    }

    // Calculate the values of `b` based on the initial assumption that `a[0]` is zero
    b[0] = c[0][0];
    b[1] = c[0][1];
    b[2] = c[0][2];

    // Calculate the values of `a` based on the values in `c`
    a[0] = 0; // Assuming a[0] is zero
    a[1] = c[1][0] - c[0][0];
    a[2] = c[2][0] - c[0][0];

    // Check if the calculated values of `a` and `c` are consistent with the given relationships
    if (a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
        a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
