

#include <iostream>
#include <algorithm>

int main() {
    // Initialize an integer array named in with a length of 3
    int in[3];

    // Use std::cin to read three integers from the standard input and store them in the array in
    std::cin >> in[0] >> in[1] >> in[2];

    // Sort the integers in ascending order using std::sort function
    std::sort(in, in + 3);

    // Multiply the last integer by 10 and add the second last and the last integer
    // Then print the result using std::cout
    std::cout << in[2] * 10 + in[1] + in[0] << std::endl;

    // End of code
    return 0;
}

