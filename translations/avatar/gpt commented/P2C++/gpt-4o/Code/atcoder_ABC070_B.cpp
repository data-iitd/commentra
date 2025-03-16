#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read a line of input, split it into components, and convert each component to an integer, storing them in a vector A
    std::vector<int> A(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> A[i];
    }

    // Check if the second element is less than or equal to the third element, or if the fourth element is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0]) {
        // If the condition is true, print 0
        std::cout << 0 << std::endl;
    } else {
        // If the condition is false, sort the vector A in ascending order
        std::sort(A.begin(), A.end());
        // Calculate the difference between the largest and the second largest elements in the sorted vector and print the result
        std::cout << A[2] - A[1] << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
