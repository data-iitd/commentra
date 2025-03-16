
#include <iostream> // Include the necessary libraries for input and output operations
#include <string> // Include the string library for string manipulation
#include <cstdio> // Include the cstdio library for file input and output operations
#include <cstdlib> // Include the cstdlib library for memory allocation and deallocation
#include <cmath> // Include the cmath library for mathematical operations
#include <vector> // Include the vector library for dynamic arrays
#include <map> // Include the map library for associative arrays
#include <set> // Include the set library for sets
#include <queue> // Include the queue library for queues
#include <stack> // Include the stack library for stacks
#include <algorithm> // Include the algorithm library for various algorithms

using namespace std; // Use the standard namespace for convenience

// Define the main function to run the program
int main() {
    freopen("input.txt", "r", stdin); // Redirect the input stream to read from a file named "input.txt"
    freopen("output.txt", "w", stdout); // Redirect the output stream to write to a file named "output.txt"
    string S; // Declare a string variable S to store the input string
    cin >> S; // Read the input string from the input stream
    int score = 0; // Initialize the score to 0
    // Iterate through each character in the string S
    for (int i = 0; i < S.length(); i++) {
        char my = i % 2 == 0? 'g' : 'p'; // Determine the expected character based on the index
        char his = S[i]; // Get the character at the current index in S
        // Compare the expected character with the actual character and update the score
        if (my!= his) {
            score += my == 'p'? 1 : -1; // Update the score based on the expected character
        }
    }
    cout << score << endl; // Print the final score to the output stream
    return 0; // Return 0 to indicate successful program execution
}

// Translate the above C++ code to Python and end with comment "