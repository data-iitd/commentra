#include <iostream>
#include <vector>

int main() {
    // Initialize variable N to store the number of elements in the array
    int N;
    std::cin >> N; // Read the number of elements from the standard input

    // Initialize a vector 'v' of size N to store the frequency of each element
    std::vector<int> v(N, 0);

    // Iterate through the input elements and update the frequency in the vector 'v'
    for (int i = 1; i < N; i++) {
        int a;
        std::cin >> a; // Read the next element from the standard input
        // Update the frequency of the element 'a-1' in the vector 'v'
        v[a - 1]++;
    }

    // Iterate through the vector 'v' and print each element to the standard output
    for (const auto& e : v) {
        std::cout << e << std::endl; // Print each element to the standard output
    }

    // End of the code
    return 0;
}

// <END-OF-CODE>
