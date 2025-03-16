#include <iostream> // For input and output
#include <string>   // For string manipulation
#include <sstream>  // For string stream
#include <vector>   // For vector

using namespace std;

// Class for reading input
class LightScanner {
    istream &in; // Input stream reference
public:
    LightScanner(istream &input) : in(input) {} // Constructor

    string stringInput() {
        string line;
        if (getline(in, line)) { // Read a line from the input stream
            return line; // Return the line
        }
        throw runtime_error("No more input"); // Throw an error if no input
    }
};

// Class for solving the problem
class BUnhappyHackingABCEdit {
public:
    void solve(int testNumber, LightScanner &in, ostream &out) {
        string s = in.stringInput(); // Read the input string
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
                    if (!d.empty()) { // If there is a character in the output string
                        d.pop_back(); // Remove the last character from the output string
                    }
                    break;
            }
        }

        out << d << endl; // Print the output string to the console
    }
};

// Main function
int main() {
    LightScanner in(cin); // Initialize LightScanner for reading input
    BUnhappyHackingABCEdit solver; // Initialize the solver

    int testNumber = 1; // Test case number
    solver.solve(testNumber, in, cout); // Run the solver with the given input and output streams

    return 0; // Return success
}

// <END-OF-CODE>
