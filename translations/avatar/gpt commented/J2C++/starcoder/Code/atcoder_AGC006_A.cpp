#include <bits/stdc++.h>
using namespace std;

// Define a constant for the maximum size of the arrays
const int N = 200 + 10; 
// Array to store the failure function values
int f[N]; 
// Array to store the concatenated strings
char b[N]; 

// Function to compute the failure function for the KMP algorithm
void getFail(char b[], int m) {
    int j = 0; // Initialize j to track the length of the previous longest prefix suffix
    f[0] = f[1] = 0; // Base cases for the failure function

    // Loop through the string to fill the failure function
    for (int i = 2; i <= m; i++) {
        // Adjust j until we find a match or j becomes 0
        while (j > 0 && b[j + 1]!= b[i]) 
            j = f[j]; 
        // If there is a match, increment j
        if (b[j + 1] == b[i]) 
            j++; 
        // Set the failure function value for the current position
        f[i] = j; 
    }
}

int main() {
    // Create an input reader and output writer
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    InputReader in = new InputReader(cin); 
    OutputWriter out = new OutputWriter(cout); 

    // Read the length of the strings
    int n = in.nextInt(); 
    // Read the two strings
    string s1 = in.next(), str = in.next(); 
    int cnt = 0; 

    // Concatenate the second string into the character array
    for (int i = 0; i < n; i++) 
        b[++cnt] = str.charAt(i); 
    // Concatenate the first string into the character array
    for (int i = 0; i < n; i++) 
        b[++cnt] = s1.charAt(i); 

    // Compute the failure function for the concatenated strings
    getFail(b, cnt); 

    // Calculate the length of the longest prefix which is also a suffix
    int len = min(f[cnt], min(n, n)); 
    // Output the result based on the calculated length
    out.print(2 * n - len); 
    out.flush(); // Ensure all output is written
    return 0;
}

// Class to handle input reading
class InputReader {
public:
    // BufferedReader for efficient input
    BufferedReader *reader; 
    // Tokenizer to split input into tokens
    StringTokenizer *tokenizer; 

    // Constructor to initialize the input reader
    InputReader(istream &stream) {
        reader = new BufferedReader(&stream, 32768); 
        tokenizer = NULL; 
    }

    // Method to read the next token from input
    string next() {
        // Read a new line if the tokenizer is null or has no more tokens
        while (tokenizer == NULL ||!tokenizer->hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader->readLine()); 
            } catch (IOException e) {
                throw new RuntimeException(e); 
            }
        }
        return tokenizer->nextToken(); // Return the next token
    }

    // Method to read the next integer from input
    int nextInt() {
        return Integer.parseInt(next()); // Parse and return the next token as an integer
    }
};

// Class to handle output writing
class OutputWriter {
public:
    // Stream to write output to
    ostream *writer; 

    // Constructor to initialize the output writer
    OutputWriter(ostream &stream) {
        writer = &stream; 
    }

    // Method to write a single character to output
    void print(char c) {
        writer->put(c); 
    }

    // Method to write a string to output
    void print(string s) {
        writer->write(s.c_str()); 
    }

    // Method to write a new line to output
    void println() {
        writer->put('\n'); 
    }

    // Method to write a string followed by a new line to output
    void println(string s) {
        print(s); 
        println(); 
    }

    // Method to flush output
    void flush() {
        writer->flush(); 
    }
};

