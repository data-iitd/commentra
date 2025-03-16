#include <iostream> // Input and output stream
#include <string>   // String class
#include <sstream>  // String stream for output
using namespace std;

class BABC {
public:
    // Method for solving the problem
    void solve(int testNumber, istream &in, ostream &out) {
        string s;
        in >> s; // Read the input string

        // Replace all occurrences of "BC" with "D" in the input string
        size_t pos;
        while ((pos = s.find("BC")) != string::npos) {
            s.replace(pos, 2, "D");
        }

        long long cnt = 0; // Initialize counter for the number of "D"s
        long long tmp = 0; // Initialize temporary variable for counting consecutive "A"s

        for (char c : s) {
            // Loop through each character in the string
            if (c == 'A') {
                // If the character is "A", increment the temporary counter
                tmp++;
            } else if (c == 'D') {
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
    BABC solver; // Create a new instance of the BABC class
    solver.solve(1, cin, cout); // Solve the problem and print the result
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
