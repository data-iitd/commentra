#include <iostream>
#include <string>

using namespace std;

class TaskD {
public:
    void solve(int testNumber, istream &in, ostream &out) {
        // Read the input string S
        string S;
        in >> S;
        int score = 0; // Initialize score to zero

        // Iterate through each character in the string S
        for (int i = 0; i < S.length(); i++) {
            // Determine the character for 'my' based on the index (even or odd)
            char my = (i % 2 == 0) ? 'g' : 'p';

            // Get the character from the input string at the current index
            char his = S[i];

            // Compare 'my' and 'his' characters to update the score
            if (my != his) {
                // Increment score if 'my' is 'p', otherwise decrement
                score += (my == 'p') ? 1 : -1;
            }
        }

        // Output the final score
        out << score << endl;
    }
};

int main() {
    // Create an instance of TaskD to solve the problem
    TaskD solver;

    // Call the solve method with test number, input stream, and output stream
    solver.solve(1, cin, cout);

    return 0;
}

// <END-OF-CODE>
