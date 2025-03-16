

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> A(4);  // Creating a vector of size 4 to store the input
    for (int i = 0; i < 4; i++) {
        std::cin >> A[i];  // Taking input from the user and storing it in the vector
    }

    // Checking if the second element is less than or equal to the third element or if the fourth element is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0]) {
        std::cout << 0 << std::endl;  // If either condition is true, print 0
    } else {
        std::sort(A.begin(), A.end());  // Sorting the vector
        std::cout << A[2] - A[1] << std::endl;  // Printing the difference between the third and second elements
    }

    return 0;
}

