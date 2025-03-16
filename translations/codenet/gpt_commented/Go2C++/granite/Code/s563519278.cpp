
#include <iostream>
#include <vector>
#include <string>

int main() {
    // Declare a variable N to hold the number of elements
    int N;
    // Read the integer N from standard input
    std::cin >> N;

    // Create a vector v of size N to hold counts of occurrences
    std::vector<int> v(N);
    int a;

    // Loop through the range from 1 to N-1 to read N-1 integers
    for (int i = 1; i < N; i++) {
        // Read the next word from input
        std::string word;
        std::cin >> word;
        // Convert the word to an integer
        a = std::stoi(word);
        // Increment the count at the index corresponding to the value read (adjusted for 0-based index)
        v[a-1]++;
    }

    // Loop through the vector v to print the counts of occurrences
    for (int i = 0; i < N; i++) {
        // Print each count to the output
        std::cout << v[i] << std::endl;
    }

    return 0;
}

