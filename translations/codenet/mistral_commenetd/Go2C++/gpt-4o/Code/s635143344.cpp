#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Initialize a vector of integers with a size of 3
    std::vector<int> in(3);

    // Use std::cin to read three integers from the standard input and store them in the vector in
    std::cin >> in[0] >> in[1] >> in[2];

    // Sort the integers in ascending order using std::sort
    std::sort(in.begin(), in.end());

    // Multiply the last integer by 10 and add the second last and the last integer
    // Then print the result using std::cout
    std::cout << in[2] * 10 + in[1] + in[0] << std::endl;

    return 0;
}

// <END-OF-CODE>
