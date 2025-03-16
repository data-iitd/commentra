#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> A;
    int num;
    std::string input;
    
    // Read a line of input
    std::getline(std::cin, input);
    
    // Split the input into components and convert each component to an integer, storing them in vector A
    std::stringstream ss(input);
    while (ss >> num) {
        A.push_back(num);
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

