#include <iostream> // For input and output operations
#include <vector>   // For using vectors
#include <algorithm> // For the reverse function
#include <sstream>  // For string stream operations

// Function to read the next integer from the input
int nextInt(std::istringstream &iss) {
    int t;
    iss >> t;
    return t;
}

// Function to reverse a segment of the vector in place
void reva(std::vector<int> &b, int start, int end) {
    std::reverse(b.begin() + start, b.begin() + end);
}

// Main function
int main() {
    std::string input;
    std::getline(std::cin, input); // Read the entire input line
    std::istringstream iss(input); // Create a string stream from the input

    int n = nextInt(iss); // Read the number of elements
    std::vector<int> a(n); // Initialize a vector of integers with size n
    for (int i = 0; i < n; i++) {
        a[i] = nextInt(iss); // Read each element and assign it to the vector
    }

    int q = nextInt(iss); // Read the number of queries
    for (int i = 0; i < q; i++) {
        int b = nextInt(iss); // Read the start index of the segment to reverse
        int e = nextInt(iss); // Read the end index of the segment to reverse
        reva(a, b, e); // Reverse the segment of the array
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            std::cout << " "; // Adds a space between elements, except before the first element
        }
        std::cout << a[i]; // Writes the element to the output
    }
    std::cout << std::endl; // Adds a newline after all elements

    return 0; // Return success
}

// <END-OF-CODE>
