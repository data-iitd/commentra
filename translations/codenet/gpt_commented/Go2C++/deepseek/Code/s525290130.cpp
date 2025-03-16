#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

// Function to read the next integer from the input
int nextInt(std::istream& is) {
    std::string line;
    std::getline(is, line);
    return std::stoi(line);
}

// Function to reverse a slice of integers in place
void reva(std::vector<int>& b) {
    int n = b.size();
    for (int i = 0; i < n / 2; ++i) {
        std::swap(b[i], b[n - 1 - i]);
    }
}

int main() {
    std::istringstream iss(std::cin.rdbuf()); // Read from standard input

    // Read the number of elements in the array
    int n = nextInt(iss);
    std::vector<int> a(n);

    // Populate the vector with integers from input
    for (int i = 0; i < n; ++i) {
        a[i] = nextInt(iss);
    }

    // Read the number of queries
    int q = nextInt(iss);
    // Process each query
    for (int i = 0; i < q; ++i) {
        int b = nextInt(iss); // Read the starting index for the reversal
        int e = nextInt(iss); // Read the ending index for the reversal
        reva(std::vector<int>(a.begin() + b, a.begin() + e)); // Reverse the vector from index b to e
    }

    // Output the modified array
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            std::cout << " "; // Print a space before each element except the first
        }
        std::cout << a[i]; // Print the current element
    }
    std::cout << std::endl; // Print a newline after the output

    return 0;
}
