#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> A;
    int num;

    // Read the input and populate the vector 'A'
    while (std::cin >> num) {
        A.push_back(num);
        if (std::cin.peek() == ' ') {
            break;
        }
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

