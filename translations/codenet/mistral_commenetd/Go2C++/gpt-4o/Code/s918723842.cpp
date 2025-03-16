// Include necessary headers
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a < b) ? b : a;
}

// Main function
int main() {
    // Read height H, width W, and number of obstacles N from standard input
    int H, W, N;
    std::cin >> H >> W >> N;

    // Calculate the maximum dimension A between H and W
    int A = max(H, W);

    // Print the result, which is the number of rows or columns needed to place all obstacles without overlapping
    std::cout << (N + A - 1) / A << std::endl;

    return 0;
}

// <END-OF-CODE>
