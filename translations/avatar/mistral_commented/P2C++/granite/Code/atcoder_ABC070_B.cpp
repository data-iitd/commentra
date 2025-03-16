
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Create a vector 'A' from the input, which is a sequence of space-separated integers
    std::vector<int> A;
    int tmp;
    while (std::cin >> tmp) {
        A.push_back(tmp);
    }

    // Check if the second or third element of the vector 'A' is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0]) {
        // If the condition is true, print '0'
        std::cout << 0 << std::endl;
    } else {
        // If the condition is false, sort the vector 'A' in ascending order
        std::sort(A.begin(), A.end());

        // Print the difference between the third and second elements of the sorted vector
        std::cout << A[2] - A[1] << std::endl;
    }

    return 0;
}
