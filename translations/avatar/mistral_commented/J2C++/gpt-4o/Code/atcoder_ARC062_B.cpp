#include <iostream> // For input and output
#include <string> // For string handling
#include <sstream> // For string stream
#include <vector> // For vector handling

using namespace std;

class InputReader {
    istream &stream; // Input stream reference
public:
    InputReader(istream &input) : stream(input) {} // Constructor to initialize input stream

    string next() {
        string token; // Variable to store the next token
        stream >> token; // Read the next token from the input stream
        return token; // Return the token
    }
};

class TaskD {
public:
    void solve(int testNumber, InputReader &in, ostream &out) {
        string S; // String to store the input
        int score = 0; // Variable to store the score

        // Read the input string
        S = in.next();

        // Iterate through each character in the string
        for (size_t i = 0; i < S.length(); i++) {
            char my; // Character representing my move
            char his; // Character representing his move

            // Determine my move based on the index
            my = (i % 2 == 0) ? 'g' : 'p';

            // Read his move from the input string
            his = S[i];

            // Update the score based on the moves
            if (my != his) {
                score += (my == 'p') ? 1 : -1;
            }
        }

        // Print the score
        out << score << endl;
    }
};

int main() {
    InputReader in(cin); // Create InputReader object
    TaskD solver; // Create TaskD object
    solver.solve(1, in, cout); // Solve the problem and print output
    return 0; // Return success
}

// <END-OF-CODE>
