#include <iostream> // Import necessary classes for input/output operations
#include <string> // Import string for efficient string handling
#include <cctype> // Import cctype for character handling
#include <cstdlib> // Import cstdlib for string to integer conversion

using namespace std; // Use the standard namespace

// Define the SimpleScanner class to simplify input reading
class SimpleScanner {
private:
    static const int BUFFER_SIZE = 10240; // Define the buffer size
    istream *in; // The input stream to read from
    char buffer[BUFFER_SIZE]; // The buffer to hold characters
    bool eof; // Flag to indicate end of file

public:
    // Constructor to initialize the SimpleScanner with an InputStream
    SimpleScanner(istream *in) {
        this->in = in;
        eof = false;
    }

    // Method to read a character from the buffer or input stream
    char read() {
        if (in->peek() == EOF) {
            eof = true;
            return '\0';
        }
        in->read(buffer, BUFFER_SIZE);
        return buffer[0];
    }

    // Method to check if the end of file has been reached
    void checkEof() {
        if (eof) throw new NoSuchElementException();
    }

    // Method to read the next character
    char nextChar() {
        checkEof();
        char b = read();
        checkEof();
        return b;
    }

    // Method to read the next string
    string next() {
        char b;
        do {
            b = read();
            checkEof();
        } while (isspace(b));
        string sb;
        do {
            sb += b;
            b = read();
        } while (!eof && !isspace(b));
        return sb;
    }

    // Method to read the next integer
    int nextInt() {
        return atoi(next().c_str());
    }

    // Method to read the next long integer
    long nextLong() {
        return atol(next().c_str());
    }

    // Method to read the next double
    double nextDouble() {
        return atof(next().c_str());
    }
};

// Define the Main class to hold the main method
class Main {
public:
    // Define the main method
    static void main(string[] args) {
        // Create a SimpleScanner instance to read from standard input
        SimpleScanner scanner = new SimpleScanner(cin);
        // Create a PrintWriter instance to write to standard output
        PrintWriter writer = new PrintWriter(cout);

        // Read three integers from the input
        int r = scanner.nextInt();
        int d = scanner.nextInt();
        long x = scanner.nextLong();

        // Perform the calculation in a loop and print the result 10 times
        for (int i = 0; i < 10; ++i) {
            x = r * x - d;
            writer.println(x);
        }

        // Close the PrintWriter to ensure all data is flushed to the output
        writer.close();
    }
};

// End of code
