#include <iostream>
#include <vector>
#include <sstream>

int main() {
    // Initialize a 3x3 2D vector 'c' to store input matrix elements
    std::vector<std::vector<int>> c(3, std::vector<int>(3));

    // Initialize two 1D vectors 'a' and 'b' to store differences between corresponding elements of rows and columns
    std::vector<int> a(3, 0), b(3);

    // Read input matrix elements from stdin and store them in 'c' vector
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> c[i][j];
            // Add a comment explaining the current loop iteration
            // This comment will be helpful for understanding the code flow
            std::cout << "Reading element " << i << "," << j << " from input matrix\n";
        }
    }

    // Calculate differences between corresponding elements of rows and columns and store them in 'a' and 'b' vectors
    b[0] = c[0][0] - a[0];
    b[1] = c[0][1] - a[0];
    b[2] = c[0][2] - a[0];
    a[1] = c[1][0] - c[0][0];
    a[2] = c[2][0] - c[0][0];

    // Check if 'a' and 'b' vectors are equal to the differences between corresponding elements of the first row and the first column of the matrix
    if (a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
        a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
        // Print "Yes" if the condition is true, indicating that the matrix is a diagonal matrix
        std::cout << "Yes\n";
    } else {
        // Print "No" if the condition is false, indicating that the matrix is not a diagonal matrix
        std::cout << "No\n";
    }

    return 0;
}
