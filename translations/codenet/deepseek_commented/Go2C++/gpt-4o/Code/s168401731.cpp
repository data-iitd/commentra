#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Function to read the next integer from the input stream.
int getNextInt(istringstream &iss) {
    int i;
    iss >> i;
    return i;
}

// Main function handles file input/output operations based on command-line arguments.
int main(int argc, char *argv[]) {
    istream *inputStream = &cin;
    ostream *outputStream = &cout;

    // Check if command-line arguments are provided for file input/output.
    if (argc > 1) {
        ifstream inputFile(argv[1]);
        inputStream = &inputFile;
        if (argc > 2) {
            ofstream outputFile(argv[2]);
            outputStream = &outputFile;
        }
    }

    // Read the number of integers to process.
    int n;
    *inputStream >> n;

    // Initialize the answer to "second".
    string ans = "second";
    for (int i = 0; i < n; i++) {
        int a;
        *inputStream >> a;
        if (a % 2 == 1) {
            ans = "first";
            break;
        }
    }

    // Print the result based on the condition.
    *outputStream << ans << endl;

    return 0;
}

// <END-OF-CODE>
