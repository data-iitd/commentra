
#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cmath> 
#include <ctime> 
#include <cctype> 
#include <cassert> 
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <algorithm> 
#include <numeric> 
#include <functional> 

using namespace std; 

int main(int argc, char *argv[]) 
{ 
    // Create a SimpleScanner instance to read input from the standard input stream
    SimpleScanner scanner(cin); 

    // Create a PrintWriter instance to output results to the standard output stream
    PrintWriter writer(cout); 

    // Read integer values for r and d, and a long value for x from the input
    int r = scanner.nextInt(); 
    int d = scanner.nextInt(); 
    long x = scanner.nextLong(); 

    // Perform the calculation and output the result 10 times
    for (int i = 0; i < 10; ++i) { 
        // Update x according to the formula x = r * x - d
        x = r * x - d; 
        // Print the updated value of x
        writer.println(x); 
    } 

    // Close the PrintWriter to release resources
    writer.close(); 

    return 0; 
} 

// A custom scanner class to read input efficiently
class SimpleScanner { 
private: 
    // Define a buffer size for reading input
    static const int BUFFER_SIZE = 10240; 

    // Declare variables for input stream, character buffer, and end-of-file flag
    istream &in; 
    char buffer[BUFFER_SIZE]; 
    int bufferPos; 
    int bufferLen; 
    bool eof; 

public: 
    // Constructor to initialize the scanner with an InputStream
    SimpleScanner(istream &in) : in(in), bufferPos(0), bufferLen(0), eof(false) {} 

    // Method to read a single character from the input
    char read() { 
        // If the buffer is empty, refill it
        if (bufferPos >= bufferLen) { 
            bufferLen = in.read(buffer, 0, BUFFER_SIZE); 
            bufferPos = 0; 
            // If no characters were read, set eof flag and return null character
            if (bufferLen <= 0) { 
                eof = true; 
                return '\0'; 
            } 
        } 
        // Return the next character from the buffer
        return buffer[bufferPos++]; 
    } 

    // Method to check if the end of the input has been reached
    void checkEof() { 
        if (eof) throw runtime_error("End of input"); 
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
        } while (isspace(b)); 

        string result; 
        // Append characters until a whitespace or EOF is encountered
        do { 
            result += b; 
            b = read(); 
        } while (!eof &&!isspace(b)); 

        return result; 
    } 

    // Method to read the next integer from the input
    int nextInt() { 
        return atoi(next().c_str()); 
    } 

    // Method to read the next long value from the input
    long nextLong() { 
        return atoll(next().c_str()); 
    } 

    // Method to read the next double value from the input
    double nextDouble() { 
        return atof(next().c_str()); 
    } 
}; 

// A custom PrintWriter class to output results efficiently
class PrintWriter { 
private: 
    ostream &out; 
    buffer buf; 
    int bufPos; 
    bool autoflush; 

public: 
    // Constructor to initialize the PrintWriter with an OutputStream
    PrintWriter(ostream &out) : out(out), bufPos(0), autoflush(false) {} 

    // Method to flush the internal buffer to the output stream
    void flush() { 
        if (bufPos > 0) { 
            out.write(buf, 0, bufPos); 
            bufPos = 0; 
        } 
        out.flush(); 
    } 

    // Method to close the PrintWriter and flush any remaining output
    void close() { 
        flush(); 
        out.close(); 
    } 

    // Method to output a single character to the output stream
    void write(char x) { 
        buf[bufPos++] = x; 
        if (bufPos == BUF_SIZE) flush(); 
    } 

    // Method to output a string to the output stream
    void print(const string &s) { 
        for (int i = 0; i < s.length(); ++i) write(s[i]); 
    } 

    // Method to output a formatted string to the output stream
    void printf(const char *format,...) { 
        va_list args; 
        va_start(args, format); 
        vprintf(format, args); 
        va_end(args); 
    } 

    // Method to output a formatted string to the output stream
    void printf(const string &format,...) { 
        va_list args; 
        va_start(args, format); 
        vprintf(format.c_str(), args); 
        va_end(args); 
    } 

    // Method to output a formatted string to the output stream
    void vprintf(const char *format, va_list args) { 
        int n = vsnprintf(buf + bufPos, BUF_SIZE - bufPos, format, args); 
        if (n > BUF_SIZE - bufPos) { 
            vsnprintf(buf, BUF_SIZE, format, args); 
            flush(); 
            n = strlen(buf); 
        } 
        bufPos += n; 
    } 

    // Method to output a formatted string to the output stream
    void vprintf(const string &format, va_list args) { 
        vprintf(format.c_str(), args); 
    } 

    // Method to output a boolean value to the output stream
    void print(bool x) { 
        print(x? "true" : "false"); 
    } 

    // Method to output an integer value to the output stream
    void print(int x) { 
        printf("%d", x); 
    } 

    // Method to output a long value to the output stream
    void print(long x) { 
        printf("%ld", x); 
    } 

    // Method to output a double value to the output stream
    void print(double x) { 
        printf("%.15lf", x); 
    } 

    // Method to output a character to the output stream
    void print(char x) { 
        write(x); 
    } 

    // Method to output a newline character to the output stream
    void println() { 
        write('\n'); 
    } 

    // Method to output a string followed by a newline character to the output stream
    void println(const string &s) { 
        print(s); 
        println(); 
    } 

    // Method to output a formatted string followed by a newline character to the output stream
    void println(const char *format,...) { 
        va_list args; 
        va_start(args, format); 
        vprintf(format, args); 
        println(); 
        va_end(args); 
    } 

    // Method to output a formatted string followed by a newline character to the output stream
    void println(const string &format,...) { 
        va_list args; 
        va_start(args, format); 
        vprintf(format.c_str(), args); 
        println(); 
        va_end(args); 
    } 
}; 

