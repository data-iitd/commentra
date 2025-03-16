#include <bits/stdc++.h>
using namespace std;

int main() {
    // Set up input and output streams
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // Initialize the LightScanner for reading input
    LightScanner in = LightScanner(cin);
    // Initialize the output stream
    ofstream out("output.txt");
    // Create an instance of the problem solver
    BUnhappyHackingABCEdit solver = BUnhappyHackingABCEdit();
    // Solve the problem for the first test case
    solver.solve(1, in, out);
    // Close the output stream
    out.close();
}

class BUnhappyHackingABCEdit {
public:
    void solve(int testNumber, LightScanner in, ofstream out) {
        // Read the input string
        string s = in.string();
        // StringBuilder to construct the output string
        stringstream d;
        // Process each character in the input string
        for (char c : s) {
            switch (c) {
                case '0':
                    // Append '0' to the output
                    d << "0";
                    break;
                case '1':
                    // Append '1' to the output
                    d << "1";
                    break;
                case 'B':
                    // Handle the 'B' character by removing the last character if possible
                    if (d.str().length() > 0) {
                        d.seekp(-1, ios_base::cur); // Remove the last character
                        d.str().pop_back(); // Adjust the size of the StringBuilder
                    }
                    break;
            }
        }
        // Output the final result
        out << d.str();
    }
};

class LightScanner {
private:
    istream *reader = NULL;
    stringstream *tokenizer = NULL;

public:
    // Constructor to initialize the BufferedReader
    LightScanner(istream &in) {
        reader = &in;
    }

    // Method to read the next string token from input
    string string() {
        // Check if there are more tokens to read
        if (tokenizer == NULL ||!tokenizer->hasMoreTokens()) {
            // Read a new line and create a new StringTokenizer
            tokenizer = new stringstream(getline(*reader));
        }
        // Return the next token
        return tokenizer->nextToken();
    }
};

