#include <bits/stdc++.h>
using namespace std;

int main() {
    // Set up the standard input and output streams
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // Create an InputReader to read input from the standard input stream
    InputReader in = new InputReader(cin);
    // Create an instance of TaskB and call its solve method
    TaskB solver = new TaskB();
    solver.solve(1, in, cout);
    // Close the stream
    return 0;
}

class TaskB {
public:
    // The solve method implements the main logic
    void solve(int testNumber, InputReader in, ostream& out) {
        // Read the input string
        string x = in.next();
        // Initialize a stack to keep track of characters
        stack<char> s;
        // Initialize a counter to count balanced pairs
        int c = 0;
        // Iterate through each character in the input string
        for (int i = 0; i < x.length(); i++) {
            // Push the current character onto the stack
            s.push(x[i]);
            // While the stack has more than one element, check for balanced pairs
            while (s.size() > 1) {
                // Pop the top two elements from the stack
                char p = s.top();
                s.pop();
                char q = s.top();
                s.pop();
                // Check if they form a balanced pair
                if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                    // Increment the counter if a balanced pair is found
                    c++;
                    continue;
                } else {
                    // If not a balanced pair, push the popped elements back onto the stack
                    s.push(q);
                    s.push(p);
                    break;
                }
            }
        }
        // Output the result, which is twice the counter value
        out << c * 2 << endl;
    }
};

// Helper class to read input from the standard input stream
class InputReader {
public:
    istream& stream;
    stringstream line;
    string token;

    // Constructor to initialize the InputReader with the standard input stream
    InputReader(istream& stream) : stream(stream) {}

    // Method to read the next token from the input stream
    string next() {
        while (getline(stream, line)) {
            line >> token;
            if (token!= "") {
                return token;
            }
        }
        return "";
    }
};

