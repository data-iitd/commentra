#include <iostream>
#include <vector>

int main() {
    // Declare a variable N to hold the number of elements
    int N;
    // Read the integer N from standard input
    std::cin >> N;

    // Initialize a vector v of size N to hold counts of occurrences
    std::vector<int> v(N, 0);
    int a;

    // Loop through the range from 1 to N-1 to read N-1 integers
    for (int i = 1; i < N; i++) {
        // Read the next integer from input
        std::cin >> a;
        // Increment the count at the index corresponding to the value read (adjusted for 0-based index)
        v[a - 1]++;
    }

    // Loop through the vector v to print the counts of occurrences
    for (const auto& e : v) {
        // Output each count
        std::cout << e << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
