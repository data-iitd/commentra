
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// getScanner initializes a new bufio.Scanner with specific configurations.
bufio.Scanner* getScanner(ifstream* fp) {
    bufio.Scanner* scanner = new bufio.Scanner(*fp);
    scanner.Split(bufio.ScanWords);
    scanner.Buffer(make([]byte, 500001), 500000);
    return scanner;
}

// getNextString reads the next word from the scanner.
string getNextString(bufio.Scanner* scanner) {
    scanner.Scan();
    return scanner.Text();
}

// getNextInt reads the next word, converts it to an integer, and returns it.
int getNextInt(bufio.Scanner* scanner) {
    int i;
    stringstream(getNextString(scanner)) >> i;
    return i;
}

// getNextInt64 reads the next word, converts it to an int64, and returns it.
int64_t getNextInt64(bufio.Scanner* scanner) {
    int64_t i;
    stringstream(getNextString(scanner)) >> i;
    return i;
}

// getNextUint64 reads the next word, converts it to a uint64, and returns it.
uint64_t getNextUint64(bufio.Scanner* scanner) {
    uint64_t i;
    stringstream(getNextString(scanner)) >> i;
    return i;
}

// getNextFloat64 reads the next word, converts it to a float64, and returns it.
double getNextFloat64(bufio.Scanner* scanner) {
    double i;
    stringstream(getNextString(scanner)) >> i;
    return i;
}

// Main function handles file input/output operations based on command-line arguments.
int main(int argc, char* argv[]) {
    ifstream* fp = &cin;
    ofstream* wfp = &cout;

    // Check if command-line arguments are provided for file input/output.
    if (argc > 1) {
        fp = new ifstream(argv[1]);
        if (argc > 2) {
            wfp = new ofstream(argv[2]);
        }
    }

    bufio.Scanner* scanner = getScanner(fp);
    ostream_iterator<string> out_it(*wfp, "\n");

    // Read the number of integers to process.
    int n = getNextInt(scanner);

    // Initialize the answer to "second".
    string ans = "second";
    for (int i = 0; i < n; i++) {
        int a = getNextInt(scanner);
        if (a % 2 == 1) {
            ans = "first";
            break;
        }
    }
    // Print the result based on the condition.
    copy(out_it, ans);

    delete scanner;
    if (argc > 1) {
        delete fp;
        if (argc > 2) {
            delete wfp;
        }
    }

    return 0;
}

