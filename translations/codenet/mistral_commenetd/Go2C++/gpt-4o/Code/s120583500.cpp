#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    // Initialize an empty string variable 's' to store the input DNA sequence
    std::string s;

    // Read the input DNA sequence from the standard input
    std::cin >> s;

    // Initialize a counter variable 'count' to keep track of the number of nucleotides (A, C, G, T)
    // and a vector 'counter' to store the count of nucleotides in each sub-sequence between non-nucleotide characters
    int count = 0;
    std::vector<int> counter;

    // Check if the input DNA sequence is empty or not
    if (s.empty()) {
        // If the input DNA sequence is empty, return without doing anything
        return 0;
    }

    // Initialize the first element of the 'counter' vector with an initial count of 0
    counter.push_back(0);

    // Iterate through each character in the string 's'
    for (char nucleotide : s) {
        // Check if the current character is a valid nucleotide (A, C, G, T)
        if (nucleotide == 'A' || nucleotide == 'C' || nucleotide == 'G' || nucleotide == 'T') {
            // If the current nucleotide is valid, increment the 'count' variable
            count++;
        } else {
            // If the current nucleotide is not valid, append the current count to the 'counter' vector and reset the 'count' variable to 0
            counter.push_back(count);
            count = 0;
        }
    }

    // Append the final count of nucleotides in the last sub-sequence to the 'counter' vector
    counter.push_back(count);

    // Sort the 'counter' vector in ascending order
    std::sort(counter.begin(), counter.end());

    // Print the last element of the sorted 'counter' vector, which represents the maximum count of nucleotides in any sub-sequence
    std::cout << counter.back() << std::endl;

    return 0;
}

// <END-OF-CODE>
