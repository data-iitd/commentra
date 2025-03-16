

#include <iostream>
#include <vector>
#include <string>

int main ( ) {
    // Initialize an empty vector `L`
    std::vector < int > L;

    // Read the first input, which is the number of elements to add to the vector
    int n;
    std::cin >> n;

    // Use a for loop to iterate through each integer in the input
    for ( int k = 0; k < n; k ++ ) {
        // Read the next integer from the input
        int r;
        std::cin >> r;

        // Add `r` elements to the vector `L` with the value `r`
        for ( int i = 0; i < r; i ++ ) {
            L.push_back ( r );
        }
    }

    // Read the second input, which represents the indices of the elements to print from the vector
    std::cin >> n;

    // Use another for loop to iterate through each integer in the input
    for ( int j = 0; j < n; j ++ ) {
        // Read the next integer from the input
        int index;
        std::cin >> index;

        // Print the element at the given index using the index as an offset from the beginning of the vector
        std::cout << L [ index - 1 ] << std::endl;
    }

    return 0;
}

