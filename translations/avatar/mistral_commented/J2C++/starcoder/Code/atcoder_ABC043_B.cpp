
#include <bits/stdc++.h>

using namespace std;

// Class for reading input
class LightScanner {
public:
    LightScanner(istream &in) : in(in) {} // Initialize the LightScanner with the input stream

    string string() {
        if (tokenizer == nullptr ||!tokenizer.hasMoreTokens()) { // If there are no more tokens
            string line;
            getline(in, line); // Read a new line from the input stream
            tokenizer = new StringTokenizer(line); // Initialize the tokenizer with the new line
        }
        return tokenizer.nextToken(); // Return the next token
    }

private:
    istream &in; // Input stream for reading input
    StringTokenizer *tokenizer = nullptr; // String tokenizer for tokenizing strings
};

// Class for solving the problem
class BUnhappyHackingABCEdit {
public:
    void solve(int testNumber, LightScanner &in, ostream &out) {
        string s = in.string(); // Read the input string
        string d; // Initialize an empty string for the output

        for (char c : s) { // Iterate through each character in the input string
            switch (c) { // Switch statement to handle different characters
                case '0':
                    d += "0"; // Append "0" to the output string
                    break;
                case '1':
                    d += "1"; // Append "1" to the output string
                    break;
                case 'B':
                    if (d.length() > 0) { // If there is a character in the output string
                        d.erase(d.length() - 1); // Remove the last character from the output string
                    }
                    break;
            }
        }

        out << d; // Print the output string to the console
    }
};

// Main method that runs the program
int main() {
    ios_base::sync_with_stdio(false); // Disable synchronization between C++ standard input and output streams
    cin.tie(0); // This disables the synchronization between C++ standard input and output streams
    LightScanner in(cin); // Initialize LightScanner for reading input
    ostream out(cout); // Initialize ostream for writing output

    int testNumber = 1; // Test case number
    BUnhappyHackingABCEdit solver; // Initialize the solver

    solver.solve(testNumber, in, out); // Run the solver with the given input and output streams

    return 0;
}

