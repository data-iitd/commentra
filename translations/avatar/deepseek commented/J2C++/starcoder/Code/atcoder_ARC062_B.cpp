#include <bits/stdc++.h>
using namespace std;

// The TaskD class contains the solve method which calculates a score based on the input string
class TaskD {
public:
    // The solve method takes a test number, an InputReader instance, and a PrintWriter instance
    void solve(int testNumber, InputReader in, PrintWriter out) {
        string S = in.next(); // Read the next string from the input
        int score = 0; // Initialize the score to 0
        // Iterate through each character in the string S
        for (int i = 0; i < S.length(); i++) {
            char my = i % 2 == 0? 'g' : 'p'; // Determine the expected character based on the index
            char his = S.charAt(i); // Get the character at the current index in S
            // Compare the expected character with the actual character and update the score
            if (my!= his) {
                score += my == 'p'? 1 : -1; // Update the score based on the expected character
            }
        }
        out.println(score); // Print the final score
    }
};

// The InputReader class is used to read input efficiently
class InputReader {
public:
    BufferedReader reader; // BufferedReader for reading input
    string tokenizer; // StringTokenizer for tokenizing input strings

    // Constructor for InputReader
    InputReader(istream &stream) {
        reader = new BufferedReader(new istreambuf_iterator<char>(stream), 32768); // Create a BufferedReader with a buffer size of 32768
        tokenizer = ""; // Initialize the tokenizer as null
    }

    // Method to read the next token from the input stream
    string next() {
        while (tokenizer == "" || tokenizer.find(" ") == -1) { // Check if there are more tokens
            try {
                tokenizer = reader.readLine(); // Read the next line and tokenize it
            } catch (exception &e) {
                throw e; // Throw a RuntimeException if an IOException occurs
            }
        }
        int index = tokenizer.find(" "); // Get the index of the first space in the string
        string token = tokenizer.substr(0, index); // Get the token before the space
        tokenizer = tokenizer.substr(index + 1); // Get the token after the space
        return token; // Return the next token
    }
};

// The Main class is defined to run the program
int main() {
    ios_base::sync_with_stdio(false); // Disable synchronization between C++ streams and C streams
    cin.tie(NULL); // Disables cin buffering
    cout.tie(NULL); // Disables cout buffering
    TaskD solver; // Create an instance of TaskD
    InputReader in(cin); // Create an instance of InputReader to read input from cin
    PrintWriter out(cout); // Create an instance of PrintWriter to write output to cout
    int testNumber; // Declare a variable to hold the test number
    cin >> testNumber; // Read the next integer from the input stream
    while (testNumber--) {
        solver.solve(testNumber, in, out); // Call the solve method of TaskD
    }
    return 0;
}

