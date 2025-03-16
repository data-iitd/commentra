#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int N;
    std::cin >> N; // Read the number of elements from the standard input

    // Initialize a vector 'v' of size N to store the frequency of each element
    std::vector<int> v(N, 0);

    // Initialize a string to read the input line
    std::string line;
    std::getline(std::cin, line); // Read the rest of the line to clear the buffer
    std::getline(std::cin, line); // Read the next line containing the elements

    // Initialize a stringstream to parse the input line
    std::stringstream ss(line);
    int a;

    // Iterate through the input elements and update the frequency in the vector 'v'
    while (ss >> a) {
        // Update the frequency of the element 'a-1' in the vector 'v'
        v[a - 1]++;
    }

    // Initialize a writer to write the output to the standard output
    for (int e : v) {
        // Print each element to the standard output
        std::cout << e << std::endl;
    }

    // End of the code
    return 0;
}
