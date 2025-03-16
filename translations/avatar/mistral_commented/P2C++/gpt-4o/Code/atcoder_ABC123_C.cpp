#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    // Define a constant variable N, which is the input number
    int N;
    std::cin >> N;

    // Define a vector A, which consists of five integers, each input as a separate line
    std::vector<int> A(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> A[i];
    }

    // Calculate the minimum value in the vector A
    int min_value = *std::min_element(A.begin(), A.end());

    // Calculate the ceiling value of N divided by the minimum value in the vector A
    int ceiling_value = std::ceil(static_cast<double>(N) / min_value);

    // Add 4 to the ceiling value to get the final answer
    int final_answer = ceiling_value + 4;

    // Print the final answer
    std::cout << final_answer << std::endl;

    return 0;
}

// <END-OF-CODE>
