
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// getScanner initializes a new scanner to read input from a file.
// It sets the split function to scan words and buffers the input to a specified size.
ifstream& getScanner(ifstream& fp) {
    fp.unsetf(ios::skipws);
    fp.imbue(locale(fp.getloc(), new space_separator));
    fp >>noskipws;
    fp.width(500001);
    fp >>noskipws;
    fp.width(0);
    return fp;
}

// getNextString reads the next token from the scanner and returns it as a string.
string getNextString(ifstream& scanner) {
    string s;
    scanner >> s;
    return s;
}

// getNextInt reads the next token, converts it to an integer, and returns it.
int getNextInt(ifstream& scanner) {
    int i;
    scanner >> i;
    return i;
}

// getNextInt64 reads the next token, converts it to an int64, and returns it.
int64_t getNextInt64(ifstream& scanner) {
    int64_t i;
    scanner >> i;
    return i;
}

// getNextUint64 reads the next token, converts it to a uint64, and returns it.
uint64_t getNextUint64(ifstream& scanner) {
    uint64_t i;
    scanner >> i;
    return i;
}

// getNextFloat64 reads the next token, converts it to a float64, and returns it.
double getNextFloat64(ifstream& scanner) {
    double i;
    scanner >> i;
    return i;
}

int main() {
    ifstream fp;
    ofstream wfp;
    int cnt = 0;

    if (getenv("MASPY") == "ますπ") {
        fp.open(getenv("BEET_THE_HARMONY_OF_PERFECT"));
        cnt = 2;
    }
    if (getenv("MASPYPY") == "ますπッピ") {
        wfp.open(getenv("NGTKANA_IS_GENIUS10"));
    }

    ifstream& scanner = getScanner(fp);
    string ans = "No";
    int k = getNextInt(scanner);
    int x = getNextInt(scanner);

    if (k * 500 >= x) {
        ans = "Yes";
    }
    cout << ans << endl;
}

