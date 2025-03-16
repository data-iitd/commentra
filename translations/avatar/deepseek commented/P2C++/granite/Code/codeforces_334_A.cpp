

#include <iostream>

int main() {
    int n;
    std::cin >> n;  // Taking an integer input from the user
    int i = 1, j = n * n;  // Initializing variables i and j

    // Starting a while loop that continues as long as i is less than j
    while (i < j) {
        std::cout << i << " " << j << std::endl;  // Printing the current values of i and j
        i++;                                       // Incrementing i by 1
        j--;                                       // Decrementing j by 1
    }

    return 0;
}
