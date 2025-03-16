
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Step 1: Define the input stream and output stream
istream& inputStream = cin;
ostream& outputStream = cout;

// Step 2: Create a LightScanner instance for reading input efficiently
class LightScanner {
    private:
        istream& in;
        stringstream ss;
        vector<string> tokens;
    public:
        LightScanner(istream& in) : in(in) {
            string line;
            while (getline(in, line)) {
                ss << line;
            }
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
        }
        string string() {
            if (tokens.empty()) {
                return "";
            }
            string token = tokens.back();
            tokens.pop_back();
            return token;
        }
};

// Step 3: Create a PrintWriter instance for writing output
class PrintWriter {
    private:
        ostream& out;
    public:
        PrintWriter(ostream& out) : out(out) {
        }
        void println(string s) {
            out << s << endl;
        }
};

// Step 4: Create an instance of the problem solver
class BUnhappyHackingABCEdit {
    public:
        void solve(int testNumber, LightScanner& in, PrintWriter& out) {
            // Read the input string
            string s = in.string();
            
            // StringBuilder to build the result
            string d;
            
            // Iterate over each character in the input string
            for (char c : s) {
                switch (c) {
                    case '0':
                        // Append '0' to the result
                        d += '0';
                        break;
                    case '1':
                        // Append '1' to the result
                        d += '1';
                        break;
                    case 'B':
                        // Remove the last character if the result is not empty
                        if (!d.empty()) {
                            d.pop_back();
                        }
                        break;
                }
            }
            
            // Print the result
            out.println(d);
        }
};

int main() {
    // Step 5: Solve the problem
    BUnhappyHackingABCEdit solver;
    solver.solve(1, LightScanner(inputStream), PrintWriter(outputStream));
    return 0;
}

// 