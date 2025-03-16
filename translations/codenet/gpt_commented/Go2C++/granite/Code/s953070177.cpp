
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// getScanner initializes a new scanner for reading from the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer for large inputs.
ifstream& getScanner(ifstream& fp) {
    fp.clear();
    fp.seekg(0, ios::beg);
    fp >> noskipws;
    return fp;
}

// getNextString retrieves the next string from the scanner.
string getNextString(ifstream& scanner) {
    string s;
    scanner >> s;
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

int main() {
    // Determine the input source: standard input or a file specified as a command-line argument.
    ifstream fp;
    if (argc > 1) {
        fp.open(argv[1]);
    } else {
        fp.copyfmt(cin);
    }

    // Initialize the scanner for reading input.
    ifstream& scanner = getScanner(fp);

    // Create a buffered writer for output.
    ofstream writer("output.txt");

    // Read the number of elements from the input.
    int n = getNextInt(scanner);

    // Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
    int aa[n+2];
    int sum = 0;

    // Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
    for (int i = 0; i < n; i++) {
        aa[i+1] = getNextInt(scanner);
        sum += abs(aa[i+1] - aa[i]);
    }
    // Include the difference between the last element and the element before it.
    sum += abs(aa[n+1] - aa[n]);

    // Calculate and print the result for each element.
    for (int i = 1; i < n+1; i++) {
        // Calculate the new sum of absolute differences if the i-th element is removed.
        int ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1]);
        writer << ans << endl; // Output the result for the current element.
    }

    // Flush the buffered writer to ensure all output is written.
    writer.flush();

    return 0;
}

// abs returns the absolute value of an integer.
int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

