
#include <bits/stdc++.h>
using namespace std;

// Function to create a new scanner from a file pointer
void getScanner(FILE *fp, istringstream &scanner) {
    scanner.clear();
    scanner.str(string(stringstream::in_avail, '\0'));
    scanner.exceptions(ios::badbit | ios::failbit);
    scanner.rdbuf(fp? fp : cin.rdbuf());
}

// Function to read the next string from the scanner
string getNextString(istringstream &scanner) {
    string s;
    scanner >> s;
    return s;
}

// Function to read the next integer from the scanner
int getNextInt(istringstream &scanner) {
    int i;
    scanner >> i;
    return i;
}

// Function to read the next integer64 from the scanner
long long getNextInt64(istringstream &scanner) {
    long long i;
    scanner >> i;
    return i;
}

// Function to read the next uint64 from the scanner
unsigned long long getNextUint64(istringstream &scanner) {
    unsigned long long i;
    scanner >> i;
    return i;
}

// Function to read the next float64 from the scanner
double getNextFloat64(istringstream &scanner) {
    double i;
    scanner >> i;
    return i;
}

// Main function
int main() {
    // Open the standard input and output files
    FILE *fp = stdin;
    FILE *wfp = stdout;

    // Set the file pointers for reading and writing
    if (getenv("MASPY")) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
        int cnt = 2; // Number of test cases to be read
    }
    if (getenv("MASPYPY")) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
        int cnt = 1; // Number of test cases to be written
    }

    // Initialize the scanner and writer
    istringstream scanner;
    getScanner(fp, scanner);
    ostream_iterator<string> output_iterator(cout, "\n");
    ofstream writer(wfp);

    // Solve the problem for the given test cases
    solve(scanner, writer);
    for (int i = 0; i < cnt; i++) {
        cout << "-----------------------------------" << endl; // Print a separator for each test case
        solve(scanner, writer);
    }

    // Close the files
    fclose(fp);
    fclose(wfp);

    return 0;
}

// Function to solve the problem for a single test case
void solve(istringstream &scanner, ofstream &writer) {
    // Read the input values
    int k = getNextInt(scanner);
    int x = getNextInt(scanner);

    // Initialize the answer
    string ans = "No";

    // Check if the condition is satisfied
    if (k * 500 >= x) {
        ans = "Yes";
    }

    // Print the answer
    writer << ans << endl;
}

