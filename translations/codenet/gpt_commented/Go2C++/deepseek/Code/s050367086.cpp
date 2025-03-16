#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

// getNextString retrieves the next string from the input stream.
string getNextString(istream& is) {
    string word;
    is >> word;
    return word;
}

// getNextInt retrieves the next integer from the input stream.
int getNextInt(istream& is) {
    int i;
    is >> i;
    return i;
}

// getNextInt64 retrieves the next int64 from the input stream.
int64_t getNextInt64(istream& is) {
    int64_t i;
    is >> i;
    return i;
}

// getNextUint64 retrieves the next uint64 from the input stream.
uint64_t getNextUint64(istream& is) {
    uint64_t i;
    is >> i;
    return i;
}

// getNextFloat64 retrieves the next float64 from the input stream.
double getNextFloat64(istream& is) {
    double i;
    is >> i;
    return i;
}

// root function finds the root of the given index using path compression.
int root(int i, vector<int>& uni) {
    if (i == uni[i]) {
        return i;
    }
    uni[i] = root(uni[i], uni);
    return uni[i];
}

// MP struct holds the string and its pattern matching table.
struct MP {
    string s;
    vector<int> table;

    void init(const string& s) {
        this->s = s;
        int n = s.size();
        table.resize(n + 1, 0);
        int j = 0;
        for (int i = 1; i < n; i++) {
            while (j > 0 && s[i] != s[j]) {
                j = table[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            table[i] = j;
        }
    }
};

int main() {
    // Initialize file streams for input and output
    ifstream fp;
    ofstream wfp;

    // Check for environment variables to override input and output file streams
    if (getenv("MASPY") == string("ますピ")) {
        fp.open(getenv("BEET_THE_HARMONY_OF_PERFECT"));
    } else {
        fp.open(istream::in);
    }
    if (getenv("MASPYPY") == string("ますピッピ")) {
        wfp.open(getenv("NGTKANA_IS_GENIUS10"));
    } else {
        wfp.open(ostream::out);
    }

    // Create a string for reading input and a writer for output
    string s = getNextString(fp);
    string t = getNextString(fp);

    // Calculate lengths of the input strings
    int ns = s.size();
    int nt = t.size();

    // Create a vector to hold repeated instances of string s
    vector<string> ss(