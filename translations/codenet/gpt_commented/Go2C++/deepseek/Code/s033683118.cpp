#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Function to read the next word from the input stream.
string getNextWord(istream& is) {
    string word;
    is >> word;
    return word;
}

// Function to read the next integer from the input stream.
int getNextInt(istream& is) {
    int num;
    is >> num;
    return num;
}

// Function to read the next int64_t from the input stream.
int64_t getNextInt64(istream& is) {
    int64_t num;
    is >> num;
    return num;
}

// Function to read the next uint64_t from the input stream.
uint64_t getNextUint64(istream& is) {
    uint64_t num;
    is >> num;
    return num;
}

// Function to read the next double from the input stream.
double getNextDouble(istream& is) {
    double num;
    is >> num;
    return num;
}

// Function to solve the problem.
void solve(istream& is, ostream& os) {
    int k = getNextInt(is); // Read the first integer k.
    int x = getNextInt(is); // Read the second integer x.

    string ans = "No"; // Default answer is "No".
    if (k * 500 >= x) { // Check the condition.
        ans = "Yes"; // Update answer to "Yes" if condition is met.
    }
    os << ans << endl; // Output the result.
}

int main() {
    // Initialize input and output streams.
    istream* input = &cin;
    ostream* output = &cout;

    // Check for environment variables to determine input and output files.
    if (getenv("MASPY") == string("ますピ")) {
        input = new ifstream(getenv("BEET_THE_HARMONY_OF_PERFECT"));
    }
    if (getenv("MASPYPY") == string("ますピッピ")) {
        output = new ofstream(getenv("NGTKANA_IS_GENIUS10"));
    }

    // Read the number of times to solve the problem.
    int cnt = 0;
    if (getenv("MASPY") == string("ますピ")) {
        cnt = 2;
    }

    // Solve the problem for the first time.
    solve(*input, *output);

    // If cnt is greater than 0, solve the problem additional times.
    for (int i = 0; i < cnt; i++) {
        (*output) << "-----------------------------------" << endl;
        solve(*input, *output);
    }

    // Close the input and output streams if they were opened.
    if (getenv("MASPY") == string("ますピ")) {
        delete input;
    }
    if (getenv("MASPYPY") == string("ますピッピ")) {
        delete output;
    }

    return 0;
}
