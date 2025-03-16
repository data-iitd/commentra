
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    // Set up the standard input and output streams
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Create an InputReader to read input from the standard input stream
    InputReader in;
    // Create a PrintWriter to write output to the standard output stream
    PrintWriter out;
    // Create an instance of TaskB and call its solve method
    TaskB solver;
    solver.solve(1, in, out);
    // Close the PrintWriter to flush the output and close the stream
    out.close();
    return 0;
}

// TaskB class contains the main logic of the program
class TaskB {
public:
    // The solve method implements the main logic
    void solve(int testNumber, InputReader in, PrintWriter out) {
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
        out.println(c * 2);
    }
};

// Helper class to read input from the standard input stream
class InputReader {
public:
    // Constructor to initialize the InputReader with the standard input stream
    InputReader() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        tokenizer = null;
    }

    // Method to read the next token from the input stream
    string next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

private:
    BufferedReader reader;
    StringTokenizer tokenizer;
};

// Helper class to write output to the standard output stream
class PrintWriter {
public:
    // Constructor to initialize the PrintWriter with the standard output stream
    PrintWriter() {
        writer = new BufferedWriter(new OutputStreamWriter(System.out));
    }

    // Method to write a string to the output stream
    void println(string s) {
        try {
            writer.write(s);
            writer.write("\n");
            writer.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

private:
    BufferedWriter writer;
};

