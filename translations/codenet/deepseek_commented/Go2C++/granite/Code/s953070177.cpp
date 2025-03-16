
#include <bits/stdc++.h>

using namespace std;

// getScanner initializes a new bufio.Scanner to read from a file.
// It sets the split function to bufio.ScanWords to read words,
// and it also sets a buffer size.
bufio.Scanner* getScanner(FILE* fp) {
    bufio.Scanner* scanner = new bufio.Scanner(fp);
    scanner.Split(bufio.ScanWords);
    scanner.Buffer(make([]byte, 500001), 500000);
    return scanner;
}

// getNextString reads the next word from the scanner and returns it as a string.
string getNextString(bufio.Scanner* scanner) {
    scanner.Scan();
    return scanner.Text();
}

// getNextInt reads the next word from the scanner, converts it to an integer,
// and returns it.
int getNextInt(bufio.Scanner* scanner) {
    int i;
    stringstream(getNextString(scanner)) >> i;
    return i;
}

// getNextInt64 reads the next word from the scanner, converts it to an int64,
// and returns it.
int64_t getNextInt64(bufio.Scanner* scanner) {
    int64_t i;
    stringstream(getNextString(scanner)) >> i;
    return i;
}

// main is the entry point of the program.
// It first checks if a file name is provided as an argument,
// and if so, it opens that file for reading.
// It then initializes a scanner and a writer.
int main(int argc, char** argv) {
    FILE* fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    bufio.Scanner* scanner = getScanner(fp);

    bufio.Writer* writer = bufio.NewWriter(os.Stdout);

    // Read the number of elements.
    int n = getNextInt(scanner);

    // Initialize a slice to store the elements and a sum variable.
    vector<int> aa(n+2);
    int sum = 0;

    // Read the elements into the slice and calculate the sum of absolute differences.
    for (int i = 0; i < n; i++) {
        aa[i+1] = getNextInt(scanner);
        sum += abs(aa[i+1] - aa[i]);
    }
    sum += abs(aa[n+1] - aa[n]);

    // Calculate and print the differences for each element.
    for (int i = 1; i < n+1; i++) {
        int ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1]);
        fmt.Fprintln(writer, ans);
    }

    // Flush the writer to ensure all output is written to the output stream.
    writer.Flush();
}

// absint returns the absolute value of an integer.
int absint(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

// 