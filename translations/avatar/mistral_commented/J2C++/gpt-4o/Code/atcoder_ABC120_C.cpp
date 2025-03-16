#include <iostream> // For input and output
#include <stack> // For implementing a stack data structure
#include <string> // For using strings
#include <sstream> // For string stream
using namespace std;

class InputReader {
public:
    InputReader(istream &stream) : reader(stream) {}

    string next() {
        string token;
        reader >> token; // Reading the next token from the input
        return token; // Returning the token
    }

private:
    istream &reader; // Input stream for reading input
};

class TaskB {
public:
    void solve(int testNumber, InputReader &in, ostream &out) {
        string x; // String to store the input string
        stack<char> s; // Stack to store characters
        int c = 0; // Counter to store the number of pairs

        x = in.next(); // Reading the input string

        // Iterating through each character in the input string
        for (char ch : x) {
            s.push(ch); // Pushing the character onto the stack

            // Popping two characters from the stack and checking for a pair
            while (s.size() > 1) {
                char p = s.top(); // Getting the top character
                s.pop(); // Popping the top character
                char q = s.top(); // Getting the second top character
                s.pop(); // Popping the second top character

                // If the popped characters form a pair, increment the counter and continue
                if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                    c++;
                    continue;
                }

                // If the characters don't form a pair, push them back onto the stack and break
                s.push(q);
                s.push(p);
                break;
            }
        }

        // Writing the output to the ostream object
        out << c * 2 << endl;
    }
};

int main() {
    InputReader in(cin); // Creating an InputReader object
    TaskB solver; // Creating a TaskB object
    solver.solve(1, in, cout); // Calling the solve method of TaskB class
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
