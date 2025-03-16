

#include <iostream> // Input/output stream for console
#include <string> // String class for manipulating strings
#include <cstdio> // Standard input/output functions

using namespace std;

class BABC {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        // Method for solving the problem

        string s; // Input string
        getline(in, s); // Read the input string from the console

        long long cnt = 0; // Initialize counter for the number of "D"s
        long long tmp = 0; // Initialize temporary variable for counting consecutive "A"s

        for (int i = 0; i < s.length(); i++) {
            // Loop through each character in the string

            if (s[i] == 'A') {
                // If the character is "A", increment the temporary counter
                tmp++;
            } else if (s[i] == 'D') {
                // If the character is "D", add the temporary counter to the total count
                cnt += tmp;
            } else {
                // If the character is neither "A" nor "D", reset the temporary counter
                tmp = 0;
            }
        }

        // Print the result
        out << cnt << endl;
    }
};

int main() {
    // Main method that starts the program

    BABC solver; // Create a new instance of the BABC class
    solver.solve(1, cin, cout); // Solve the problem and print the result

    return 0;
}

These comments should provide a clear understanding of the logic behind each part of the code. Let me know if you need any further clarification or modification.

