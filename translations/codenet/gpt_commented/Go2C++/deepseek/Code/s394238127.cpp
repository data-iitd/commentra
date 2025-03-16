#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::vector<std::vector<int>> c(3, std::vector<int>(3));
    std::vector<int> a(3), b(3);
    std::string line;

    // Read 3x3 integers from input
    for (int i = 0; i < 3; ++i) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        for (int j = 0; j < 3; ++j) {
            iss >> c[i][j];
        }
    }

    // Calculate the first differences based on the first row of 'c'
    b[0] = c[0][0] - a[0];
    b[1] = c[0][1] - a[0];
    b[2] = c[0][2] - a[0];

    // Calculate the differences for the second and third rows based on the first row
    a[1] = c[1][0] - c[0][0];
    a[2] = c[2][0] - c[0][0];

    // Check if the calculated differences are consistent across the matrix
    if (a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
        a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
        // If the conditions are met, print "Yes"
        std::cout << "Yes" << std::endl;
    } else {
        // If the conditions are not met, print "No"
        std::cout << "No" << std::endl;
    }

    return 0;
}
