
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// getScanner initializes a new scanner for reading from the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer for larger inputs.
ifstream& getScanner(ifstream& fp) {
    fp.unsetf(ios::skipws);
    fp.imbue(locale("C"));
    fp >> noskipws;
    fp >> ws;
    return fp;
}

// getNextString retrieves the next string from the scanner.
string getNextString(ifstream& scanner) {
    string s;
    getline(scanner, s,'');
    return s;
}

// getNextInt converts the next string from the scanner to an integer.
int getNextInt(ifstream& scanner) {
    int i;
    scanner >> i;
    return i;
}

// getNextInt64 converts the next string from the scanner to a 64-bit integer.
long long getNextInt64(ifstream& scanner) {
    long long i;
    scanner >> i;
    return i;
}

// getNextUint64 converts the next string from the scanner to an unsigned 64-bit integer.
unsigned long long getNextUint64(ifstream& scanner) {
    unsigned long long i;
    scanner >> i;
    return i;
}

// getNextFloat64 converts the next string from the scanner to a float64.
double getNextFloat64(ifstream& scanner) {
    double i;
    scanner >> i;
    return i;
}

int main() {
    // Initialize file pointers for input and output.
    ifstream fp;
    ofstream wfp;
    int cnt = 0;

    // Check for environment variables to determine input and output files.
    if (getenv("MASPY") == "ますπ") {
        fp.open(getenv("BEET_THE_HARMONY_OF_PERFECT"));
        cnt = 2; // Set the count for additional processing.
    }
    if (getenv("MASPYPY") == "ますπッピ") {
        wfp.open(getenv("NGTKANA_IS_GENIUS10"));
    }

    // Create a scanner for reading input and a writer for output.
    ifstream& scanner = getScanner(fp);
    ofstream& writer = wfp;

    // Solve the problem for the first time.
    solve(scanner, writer);

    // If cnt is greater than 0, solve the problem additional times.
    for (int i = 0; i < cnt; i++) {
        writer << "-----------------------------------" << endl;
        solve(scanner, writer);
    }

    // Flush the writer to ensure all output is written.
    writer.flush();
}

// solve processes the input values and determines if the condition is met.
// It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
void solve(ifstream& scanner, ofstream& writer) {
    int k = getNextInt(scanner); // Read the first integer k.
    int x = getNextInt(scanner); // Read the second integer x.

    string ans = "No"; // Default answer is "No".
    if (k * 500 >= x) { // Check the condition.
        ans = "Yes"; // Update answer to "Yes" if condition is met.
    }
    writer << ans << endl; // Output the result.
}

// END-OF-CODE