#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cctype>
#include <climits>
#include <string>
#include <utility>
#include <bitset>
#include <cfloat>
#include <cassert>

using namespace std;

int main() {
    // Declare variables for input stream, character buffer, and end-of-file flag
    char b;
    char buffer[10240];
    bool eof = false;
    
    // Create a SimpleScanner instance to read input from the standard input stream
    SimpleScanner scanner(cin);
    
    // Read integer values for r and d, and a long value for x from the input
    int r = scanner.nextInt();
    int d = scanner.nextInt();
    long x = scanner.nextLong();
    
    // Perform the calculation and output the result 10 times
    for (int i = 0; i < 10; ++i) {
        // Update x according to the formula x = r * x - d
        x = r * x - d;
        // Print the updated value of x
        printf("%ld\n", x);
    }
    
    // Close the input stream to release resources
    return 0;
}

class SimpleScanner {
    // Define a buffer size for reading input
    private static final int BUFFER_SIZE = 10240;
    
    // Declare variables for input stream, character buffer, and end-of-file flag
    private FILE *in;
    private char buffer[BUFFER_SIZE];
    private bool eof;
    
    // Constructor to initialize the scanner with an InputStream
    SimpleScanner(istream &in) {
        // Wrap the input stream in a BufferedReader for efficient reading
        this.in = new ifstream(in);
        buffer = new char[BUFFER_SIZE];
        buffer.limit(0);
        eof = false;
    }
    
    // Method to read a single character from the input
    private char read() {
        // If the buffer is empty, refill it
        if (!buffer.hasRemaining()) {
            buffer.clear();
            int n;
            try {
                n = in.read(buffer);
            } catch (IOException e) {
                n = -1;
            }
            // If no characters were read, set eof flag and return null character
            if (n <= 0) {
                eof = true;
                return '\0';
            }
            buffer.flip();
        }
        // Return the next character from the buffer
        return buffer.get();
    }
    
    // Method to check if the end of the input has been reached
    void checkEof() {
        if (eof) throw new NoSuchElementException();
    }
    
    // Method to read the next character, ensuring EOF is checked
    char nextChar() {
        checkEof();
        char b = read();
        checkEof();
        return b;
    }
    
    // Method to read the next token as a String
    string next() {
        char b;
        // Skip any whitespace characters
        do {
            b = read();
            checkEof();
        } while (Character.isWhitespace(b));
        
        StringBuilder sb = new StringBuilder();
        // Append characters until a whitespace or EOF is encountered
        do {
            sb.append(b);
            b = read();
        } while (!eof &&!Character.isWhitespace(b));
        
        return sb.toString();
    }
    
    // Method to read the next integer from the input
    int nextInt() {
        return Integer.valueOf(next());
    }
    
    // Method to read the next long value from the input
    long nextLong() {
        return Long.valueOf(next());
    }
    
    // Method to read the next double value from the input
    double nextDouble() {
        return Double.parseDouble(next());
    }
}

