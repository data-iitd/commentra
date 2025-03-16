#include <iostream>  // For input and output
#include <vector>    // For using vectors
#include <algorithm> // For using the min function
#include <cmath>     // For using the ceil function

int main() {
    // Read an integer input from the user
    int N;
    std::cin >> N;

    // Read 5 integer inputs from the user and store them in a vector A
    std::vector<int> A(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> A[i];
    }

    // Calculate the minimum value from the vector A, divide N by this minimum value,
    // take the ceiling of the result, and add 4 to it before printing the final result
    int min_value = *std::min_element(A.begin(), A.end());
    std::cout << static_cast<int>(std::ceil(static_cast<double>(N) / min_value)) + 4 << std::endl;

    return 0;
}

// <END-OF-CODE>
