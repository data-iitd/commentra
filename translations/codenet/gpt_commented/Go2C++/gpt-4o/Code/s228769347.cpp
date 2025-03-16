#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// Function to read integers from input
int getNextInt(istream &input) {
    int value;
    input >> value; // Read the next integer
    return value; // Return the integer
}

int main(int argc, char *argv[]) {
    istream *input = &cin; // Default input is standard input
    ostream *output = &cout; // Default output is standard output

    // Check for command-line arguments to read from a file and write to a file
    if (argc > 1) {
        input = new ifstream(argv[1]); // Open the input file if provided
        if (argc > 2) {
            output = new ofstream(argv[2]); // Create the output file if provided
        }
    }

    int n = getNextInt(*input); // Read the number of integers
    vector<int> ll(n); // Create a vector to hold the integers

    // Read n integers from the input
    for (int i = 0; i < n; i++) {
        ll[i] = getNextInt(*input); // Populate the vector with integers
    }

    sort(ll.begin(), ll.end()); // Sort the vector of integers

    int ans = 0; // Initialize the answer counter
    // Iterate through pairs of integers to find valid triplets
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1; // Start searching for the third element after the second element
            int r = n; // Set the right boundary for binary search
            // Perform binary search to find the count of valid third elements
            while (l < r) {
                int m = (l + r) / 2; // Calculate the middle index
                if (ll[m] < ll[i] + ll[j]) { // Check if the sum of the first two is greater than the middle element
                    l = m + 1; // Move the left boundary up
                } else {
                    r = m; // Move the right boundary down
                }
            }
            // Count the number of valid third elements
            ans += l - (j + 1); // Update the answer with the count of valid triplets
        }
    }
    *output << ans << endl; // Print the result to the output

    // Clean up if files were opened
    if (input != &cin) {
        delete input;
    }
    if (output != &cout) {
        delete output;
    }

    return 0; // Return success
}

// <END-OF-CODE>
