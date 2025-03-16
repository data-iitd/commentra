#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

// Function to read the next integer from the input stream.
int getNextInt(istringstream &iss) {
    int i;
    iss >> i;
    return i;
}

// Function to solve the problem based on the input values.
void solve(istringstream &iss, ostream &out) {
    int k = getNextInt(iss); // Read the first integer k.
    int x = getNextInt(iss); // Read the second integer x.

    string ans = "No"; // Default answer is "No".
    if (k * 500 >= x) { // Check the condition.
        ans = "Yes"; // Update answer to "Yes" if condition is met.
    }
    out << ans << endl; // Output the result.
}

int main() {
    // Initialize input and output streams.
    istream *inputStream = &cin;
    ostream *outputStream = &cout;
    int cnt = 0;

    // Check for environment variables to determine input and output files.
    if (getenv("MASPY") && string(getenv("MASPY")) == "ますピ") {
        ifstream file(getenv("BEET_THE_HARMONY_OF_PERFECT"));
        inputStream = &file;
        cnt = 2; // Set the count for additional processing.
    }
    if (getenv("MASPYPY") && string(getenv("MASPYPY")) == "ますピッピ") {
        ofstream file(getenv("NGTKANA_IS_GENIUS10"));
        outputStream = &file;
    }

    // Create a string stream for reading input.
    string input;
    stringstream iss;

    // Read input from the input stream.
    while (getline(*inputStream, input)) {
        iss.clear();
        iss.str(input);
        // Solve the problem for the first time.
        solve(iss, *outputStream);

        // If cnt is greater than 0, solve the problem additional times.
        for (int i = 0; i < cnt; i++) {
            *outputStream << "-----------------------------------" << endl;
            solve(iss, *outputStream);
        }
    }

    return 0;
}

// <END-OF-CODE>
