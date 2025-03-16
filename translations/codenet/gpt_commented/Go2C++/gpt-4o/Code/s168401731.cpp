#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Function to read integers from input
int getNextInt(istringstream &iss) {
    int i;
    iss >> i;
    return i;
}

int main(int argc, char *argv[]) {
    // Initialize input and output file streams
    ifstream inputFile;
    ofstream outputFile;
    istream *input = &cin; // Default to standard input
    ostream *output = &cout; // Default to standard output

    // Check for command line arguments to open input and output files
    if (argc > 1) {
        inputFile.open(argv[1]); // Open input file if provided
        input = &inputFile;
        if (argc > 2) {
            outputFile.open(argv[2]); // Create output file if provided
            output = &outputFile;
        }
    }

    // Read the number of integers to process
    string line;
    getline(*input, line);
    istringstream iss(line);
    int n = getNextInt(iss);

    // Initialize the answer as "second" and check for odd integers
    string ans = "second";
    for (int i = 0; i < n; i++) {
        getline(*input, line);
        int a = getNextInt(istringstream(line)); // Read the next integer
        if (a % 2 == 1) { // Check if the integer is odd
            ans = "first"; // If odd, set answer to "first"
            break; // Exit the loop early if an odd integer is found
        }
    }

    // Write the result to the output
    *output << ans << endl;

    // Close files if they were opened
    if (inputFile.is_open()) inputFile.close();
    if (outputFile.is_open()) outputFile.close();

    return 0;
}

// <END-OF-CODE>
