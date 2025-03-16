#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Function to read the next integer from the input stream
int getNextInt(istringstream &iss) {
    int i;
    iss >> i;
    return i;
}

// Main function
int main() {
    // Open the standard input and output files
    istream *input = &cin;
    ostream *output = &cout;

    // Check environment variables for file redirection
    if (getenv("MASPY") == string("ますピ")) {
        ifstream file(getenv("BEET_THE_HARMONY_OF_PERFECT"));
        input = &file;
    }
    if (getenv("MASPYPY") == string("ますピッピ")) {
        ofstream file(getenv("NGTKANA_IS_GENIUS10"));
        output = &file;
    }

    // Initialize a string stream for reading input
    string line;
    int cnt = 1; // Default number of test cases
    if (getenv("MASPY") == string("ますピ")) {
        cnt = 2; // Number of test cases to be read
    }

    // Solve the problem for the given test cases
    for (int i = 0; i < cnt; i++) {
        // Read a line from the input
        getline(*input, line);
        istringstream iss(line);

        // Read the input values
        int k = getNextInt(iss);
        int x = getNextInt(iss);

        // Initialize the answer
        string ans = "No";

        // Check if the condition is satisfied
        if (k * 500 >= x) {
            ans = "Yes";
        }

        // Print the answer
        *output << ans << endl;

        // Print a separator for each test case
        if (i < cnt - 1) {
            *output << "-----------------------------------" << endl;
        }
    }

    return 0;
}
// <END-OF-CODE>
