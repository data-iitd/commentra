#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Function to read the next integer from the input stream
int getNextInt(istream &input) {
    int value;
    input >> value;
    return value;
}

// Main function is the entry point of the program
int main(int argc, char *argv[]) {
    // Open standard input as default file if no arguments are provided
    istream *input = &cin;
    ofstream output;

    // Open input file if provided as an argument
    if (argc > 1) {
        input = new ifstream(argv[1]);
        // Create output file if provided as an argument
        if (argc > 2) {
            output.open(argv[2]);
        } else {
            output.open("output.txt"); // Default output file
        }
    } else {
        output.open("output.txt"); // Default output file
    }

    // Read the first integer from the input
    int n = getNextInt(*input);

    // Initialize answer variable
    string ans = "second";
    // Iterate through the input integers
    for (int i = 0; i < n; i++) {
        // Read the next integer from the input
        int a = getNextInt(*input);
        // Check if the current integer is odd
        if (a % 2 == 1) {
            // Update the answer if an odd integer is found
            ans = "first";
            // Exit the loop if only one odd integer is found
            break;
        }
    }

    // Write the answer to the output
    output << ans << endl;

    // Clean up if input was a file
    if (input != &cin) {
        delete input;
    }

    // Close the output file
    output.close();

    return 0;
}

// <END-OF-CODE>
