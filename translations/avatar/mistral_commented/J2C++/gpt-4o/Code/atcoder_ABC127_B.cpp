#include <iostream>  // Importing necessary C++ headers for input and output
#include <sstream>   // For string stream
#include <stdexcept> // For exception handling

using namespace std;

class SimpleScanner {
private:
    istream& in; // Input stream reference
    char buffer[1024]; // Buffer for reading characters
    size_t bufferSize; // Size of the buffer
    size_t currentPos; // Current position in the buffer
    bool eof; // End-of-file flag

public:
    // Constructor for initializing the SimpleScanner object
    SimpleScanner(istream& input) : in(input), bufferSize(0), currentPos(0), eof(false) {}

    // A method for reading a single character from the input stream
    char read() {
        if (currentPos >= bufferSize) {
            in.read(buffer, sizeof(buffer)); // Read into the buffer
            bufferSize = in.gcount(); // Get the number of characters read
            currentPos = 0; // Reset current position
            if (bufferSize == 0) {
                eof = true; // Set end-of-file flag if no characters are read
                return '\0'; // Return null character to indicate end-of-file
            }
        }
        return buffer[currentPos++]; // Return the current character from the buffer
    }

    // A method for checking the end-of-file condition
    void checkEof() {
        if (eof) throw std::runtime_error("End of input");
    }

    // A method for reading a single character
    char nextChar() {
        checkEof();
        char b = read();
        checkEof();
        return b;
    }

    // A method for reading a string
    string next() {
        stringstream ss;
        char b;
        do {
            b = read();
            checkEof();
            ss << b;
        } while (!eof);
        return ss.str();
    }

    // A method for reading an integer
    int nextInt() {
        return stoi(next());
    }

    // A method for reading a long integer
    long long nextLong() {
        return stoll(next());
    }

    // A method for reading a double
    double nextDouble() {
        return stod(next());
    }
};

int main() {
    SimpleScanner scanner(cin); // Creating a SimpleScanner object for reading input
    long long x;
    int r, d;

    // Reading input variables from the user
    r = scanner.nextInt(); // Reading the first integer 'r' from the user
    d = scanner.nextInt(); // Reading the second integer 'd' from the user
    x = scanner.nextLong(); // Reading the long integer 'x' from the user

    // Running the loop for 10 iterations
    for (int i = 0; i < 10; ++i) {
        // Multiplying 'r' with 'x' and subtracting 'd' from it
        x = r * x - d;

        // Writing the result to the output stream
        cout << x << endl;
    }

    return 0; // End of the program
}

// <END-OF-CODE>
