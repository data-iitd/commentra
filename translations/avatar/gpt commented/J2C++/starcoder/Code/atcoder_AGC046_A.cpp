#include <bits/stdc++.h>
using namespace std;

// FastReader class for efficient input reading
class FastReader { 
    // Member variables to store the state of the FastReader object
    istream *stream;
    istream::pos_type buffer_pos, stream_pos;
    string buffer;
    char cur_char;

    // Constructor initializes the FastReader object
    FastReader() {
        stream = &cin;
        buffer_pos = stream_pos = 0;
        read_char();
    }

    // Method to read the next character from the input stream
    void read_char() {
        if (buffer_pos == stream_pos) {
            // Read the next block of data from the input stream
            stream_pos = stream->tellg();
            buffer = string(istreambuf_iterator<char>(*stream), {});
            buffer_pos = 0;
        }
        cur_char = buffer[buffer_pos++];
    }

    // Method to read the next token from the input stream
    string next() {
        // Read the next character from the input stream if it is not already stored in the buffer
        if (buffer_pos == stream_pos) {
            read_char();
        }
        // Initialize a string to store the next token
        string ret = "";
        // Continue reading characters until a whitespace character is encountered
        while (cur_char!= EOF && cur_char!='' && cur_char!= '\n' && cur_char!= '\t') {
            // Append the current character to the return string
            ret += cur_char;
            // Read the next character from the input stream
            read_char();
        }
        // Return the next token
        return ret;
    }

    // Method to read the next token from the input stream and convert it to an integer
    int nextInt() {
        // Read the next token from the input stream
        string ret = next();
        // Return the next token as an integer
        return stoi(ret);
    }

    // Method to read the next token from the input stream and convert it to a long integer
    long long nextLong() {
        // Read the next token from the input stream
        string ret = next();
        // Return the next token as a long integer
        return stol(ret);
    }

    // Method to read the next token from the input stream and convert it to a double
    double nextDouble() {
        // Read the next token from the input stream
        string ret = next();
        // Return the next token as a double
        return stod(ret);
    }
};

// Main function
int main() {
    // Create a FastReader object to read input efficiently
    FastReader sc;
    // Create a PrintWriter object to output results
    ofstream fout;
    // Read an integer input from the user
    int x = sc.nextInt();
    // Initialize a counter to keep track of the number of rotations
    int count = 0;
    // Store the original value of x for later use
    int tmp = x;
    // Reset x to 0 for the rotation calculation
    x = 0;
    // Loop until x completes a full rotation (360 degrees)
    while (x!= 360) {
        // Increment x by the original input value
        x = x + tmp;
        // If x exceeds 360, wrap it around by subtracting 360
        if (x > 360) {
            x = x - 360;
        }
        // Increment the count of rotations
        count++;
    }
    // Output the total number of rotations needed to reach 360 degrees
    cout << count << endl;
    return 0;
}

