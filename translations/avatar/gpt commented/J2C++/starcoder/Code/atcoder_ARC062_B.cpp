#include <bits/stdc++.h>
using namespace std;

int main() {
    // Set up input and output streams
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Create an InputReader to read input from the input stream
    InputReader in = new InputReader(cin);

    // Create an instance of TaskD to solve the problem
    TaskD solver = new TaskD();

    // Call the solve method with test number, input reader, and output writer
    solver.solve(1, in, cout);

    // Close the output stream
    cout.close();
}

class TaskD {
    public:
    void solve(int testNumber, InputReader in, ostream& out) {
        // Read the input string S
        string S = in.next();
        int score = 0; // Initialize score to zero

        // Iterate through each character in the string S
        for (int i = 0; i < S.length(); i++) {
            // Determine the character for'my' based on the index (even or odd)
            char my = i % 2 == 0? 'g' : 'p';

            // Get the character from the input string at the current index
            char his = S.charAt(i);

            // Compare'my' and 'his' characters to update the score
            if (my!= his) {
                // Increment score if'my' is 'p', otherwise decrement
                score += my == 'p'? 1 : -1;
            }
        }

        // Output the final score
        out << score << endl;
    }
}

class InputReader {
    public:
    BufferedReader reader;
    StringTokenizer tokenizer;

    // Constructor to initialize BufferedReader and StringTokenizer
    InputReader(istream& stream) {
        reader = new BufferedReader(new istringstream(stream), 32768);
        tokenizer = null;
    }

    // Method to read the next token from the input
    string next() {
        // Keep reading until we have a token available
        while (tokenizer == null ||!tokenizer.hasMoreTokens()) {
            try {
                // Read a line and create a new StringTokenizer
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        // Return the next token
        return tokenizer.nextToken();
    }
}

