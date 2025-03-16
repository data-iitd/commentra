
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// getScanner initializes a new scanner for the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer size.
ifstream& getScanner(ifstream& fp) {
    fp.unsetf(ios::skipws);
    fp.imbue(locale("C"));
    fp >> noskipws;
    fp.width(500001);
    fp >> noskipws;
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

    // Check for command line arguments to open input and output files.
    if (argc > 1) {
        fp.open(argv[1]); // Open input file if provided.
        if (argc > 2) {
            wfp.open(argv[2]); // Create output file if provided.
        }
    }

    // Create a scanner for reading input and a writer for output.
    if (!fp.is_open()) {
        fp = cin;
    }
    getScanner(fp);
    if (!wfp.is_open()) {
        wfp = cout;
    }

    // Read the number of integers to process.
    int n = getNextInt(fp);

    // Initialize the answer as "second" and check for odd integers.
    string ans = "second";
    for (int i = 0; i < n; i++) {
        int a = getNextInt(fp); // Read the next integer.
        if (a % 2 == 1) { // Check if the integer is odd.
            ans = "first"; // If odd, set answer to "first".
            break; // Exit the loop early if an odd integer is found.
        }
    }

    // Write the result to the output.
    wfp << ans << endl;

    return 0;
}

