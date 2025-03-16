
#include <bits/stdc++.h>

using namespace std;

// getScanner initializes a new Scanner to read from a file pointer.
// It sets the split function to ScanWords and buffers to 500001 bytes.
ifstream& getScanner(ifstream& fp) {
    fp.unsetf(ios::skipws);
    fp.imbue(locale(fp.getloc(), new cpp_facet));
    fp >> noskipws;
    fp.precision(numeric_limits<double>::max_digits10);
    fp >> ws;
    return fp;
}

// getNextString reads the next token from the Scanner and returns it as a string.
string getNextString(ifstream& scanner) {
    string s;
    scanner >> s;
    return s;
}

// getNextInt reads the next token as a string, converts it to an integer, and returns it.
int getNextInt(ifstream& scanner) {
    int i;
    scanner >> i;
    return i;
}

// getNextInt64 reads the next token as a string, converts it to an int64, and returns it.
int64_t getNextInt64(ifstream& scanner) {
    int64_t i;
    scanner >> i;
    return i;
}

// getNextUint64 reads the next token as a string, converts it to a uint64, and returns it.
uint64_t getNextUint64(ifstream& scanner) {
    uint64_t i;
    scanner >> i;
    return i;
}

// getNextFloat64 reads the next token as a string, converts it to a float64, and returns it.
double getNextFloat64(ifstream& scanner) {
    double i;
    scanner >> i;
    return i;
}

// main function handles file input/output based on command-line arguments.
// It reads integers from the specified file or standard input, sorts them,
// and calculates the number of valid triplets (i, j, m) where i < j < m and ll[m] < ll[i] + ll[j].
int main() {
    ifstream fp;
    ofstream wfp;

    // Check if file paths are provided as command-line arguments.
    if (argc > 1) {
        fp.open(argv[1]);
        if (argc > 2) {
            wfp.open(argv[2]);
        }
    }

    ifstream& scanner = getScanner(fp);
    ofstream& writer = wfp;

    // Read the number of elements.
    int n = getNextInt(scanner);
    vector<int> ll(n);

    // Read n integers into the vector ll.
    for (int i = 0; i < n; i++) {
        ll[i] = getNextInt(scanner);
    }

    // Sort the vector ll.
    sort(ll.begin(), ll.end());

    // Initialize the answer variable.
    int ans = 0;

    // Iterate through possible triplets (i, j, m) where i < j < m.
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1;
            int r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            // Add the number of valid m's to the answer.
            ans += l - (j + 1);
        }
    }

    // Print the final answer to the standard output.
    writer << ans << endl;

    // Flush the writer to ensure all data is written to the file or standard output.
    writer.flush();

    return 0;
}

