

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// getScanner initializes and returns a new bufio.Scanner from the given file pointer
ifstream* getScanner(ifstream* fp) {
    return new ifstream(*fp);
}

// getNextString reads and returns the next word as a string from the scanner
string getNextString(ifstream* scanner) {
    string s;
    *scanner >> s;
    return s;
}

// getNextInt reads and converts the next integer from the scanner to an int
int getNextInt(ifstream* scanner) {
    int i;
    *scanner >> i;
    return i;
}

// getNextInt64 reads and converts the next integer from the scanner to an int64
long long getNextInt64(ifstream* scanner) {
    long long i;
    *scanner >> i;
    return i;
}

// getNextUint64 reads and converts the next unsigned integer from the scanner to a uint64
unsigned long long getNextUint64(ifstream* scanner) {
    unsigned long long i;
    *scanner >> i;
    return i;
}

// getNextFloat64 reads and converts the next floating-point number from the scanner to a float64
double getNextFloat64(ifstream* scanner) {
    double i;
    *scanner >> i;
    return i;
}

int main() {
    // open standard input as default file if no arguments are provided
    ifstream fp;
    // open output file if provided as an argument
    ofstream wfp;
    if (argc > 1) {
        fp.open(argv[1]);
        // create output file if provided as an argument
        if (argc > 2) {
            wfp.open(argv[2]);
        }
    }

    // initialize scanner and writer
    ifstream* scanner = getScanner(&fp);
    ofstream writer(wfp);

    // read the first integer from the input
    int n = getNextInt(scanner);

    // initialize answer variable
    string ans = "second";
    // iterate through the input integers
    for (int i = 0; i < n; i++) {
        // read the next integer from the input
        int a = getNextInt(scanner);
        // check if the current integer is odd
        if (a % 2 == 1) {
            // update the answer if an odd integer is found
            ans = "first";
            // exit the loop if only one odd integer is found
            break;
        }
    }
    // write the answer to the output
    writer << ans << endl;
    // flush the writer buffer
    writer.flush();

    // close the input and output files
    fp.close();
    wfp.close();

    return 0;
}
