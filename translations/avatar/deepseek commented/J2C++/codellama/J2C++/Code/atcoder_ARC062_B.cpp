#include <iostream> // Including the iostream header for input and output operations
#include <string> // Including the string header for string operations
#include <cstring> // Including the cstring header for string operations
#include <cstdio> // Including the cstdio header for input and output operations
#include <cstdlib> // Including the cstdlib header for input and output operations
#include <cmath> // Including the cmath header for mathematical operations
#include <algorithm> // Including the algorithm header for efficient sorting and searching
#include <vector> // Including the vector header for dynamic arrays
#include <map> // Including the map header for maps
#include <set> // Including the set header for sets
#include <unordered_map> // Including the unordered_map header for hash maps
#include <unordered_set> // Including the unordered_set header for hash sets
#include <queue> // Including the queue header for queues
#include <stack> // Including the stack header for stacks
#include <bitset> // Including the bitset header for bitsets
#include <cassert> // Including the cassert header for assertions
#include <cctype> // Including the cctype header for character operations
#include <cstdint> // Including the cstdint header for integer operations
#include <cstddef> // Including the cstddef header for pointer operations
#include <cstdlib> // Including the cstdlib header for memory management
#include <cstring> // Including the cstring header for string operations
#include <ctime> // Including the ctime header for time operations
#include <fstream> // Including the fstream header for file input and output operations
#include <iomanip> // Including the iomanip header for input and output operations
#include <ios> // Including the ios header for input and output operations
#include <iosfwd> // Including the iosfwd header for input and output operations
#include <iostream> // Including the iostream header for input and output operations
#include <istream> // Including the istream header for input operations
#include <ostream> // Including the ostream header for output operations
#include <sstream> // Including the sstream header for string operations
#include <streambuf> // Including the streambuf header for input and output operations
#include <string> // Including the string header for string operations
#include <typeinfo> // Including the typeinfo header for type operations
#include <utility> // Including the utility header for utility operations
#include <valarray> // Including the valarray header for array operations
#include <vector> // Including the vector header for dynamic arrays

// The Main class is defined to run the program
class Main {
public:
    // The main method initializes input and output streams, creates an instance of TaskD, and calls its solve method
    static void main(int argc, char* argv[]) {
        std::ifstream inputStream(argv[1]); // Get the input stream from the system
        std::ofstream outputStream(argv[2]); // Get the output stream from the system
        InputReader in(inputStream); // Create an InputReader instance to read input
        PrintWriter out(outputStream); // Create a PrintWriter instance to write output
        TaskD solver; // Create an instance of TaskD
        solver.solve(1, in, out); // Call the solve method of TaskD
        out.close(); // Close the output stream
    }
};

// The TaskD class contains the solve method which calculates a score based on the input string
class TaskD {
public:
    // The solve method takes a test number, an InputReader instance, and a PrintWriter instance
    void solve(int testNumber, InputReader& in, PrintWriter& out) {
        std::string S = in.next(); // Read the next string from the input
        int score = 0; // Initialize the score to 0
        // Iterate through each character in the string S
        for (int i = 0; i < S.length(); i++) {
            char my = i % 2 == 0 ? 'g' : 'p'; // Determine the expected character based on the index
            char his = S.at(i); // Get the character at the current index in S
            // Compare the expected character with the actual character and update the score
            if (my != his) {
                score += my == 'p' ? 1 : -1; // Update the score based on the expected character
            }
        }
        out.println(score); // Print the final score
    }
};

// The InputReader class is used to read input efficiently
class InputReader {
public:
    std::ifstream reader; // BufferedReader for reading input
    std::string tokenizer; // StringTokenizer for tokenizing input strings

    // Constructor for InputReader
    InputReader(std::ifstream& stream) {
        reader = stream; // Create a BufferedReader with a buffer size of 32768
        tokenizer = ""; // Initialize the tokenizer as null
    }

    // Method to read the next token from the input stream
    std::string next() {
        while (tokenizer == "") { // Check if there are more tokens
            std::string line; // Declare a string to store the next line
            std::getline(reader, line); // Read the next line
            tokenizer = line; // Tokenize the line
        }
        std::string token = tokenizer; // Get the next token
        tokenizer = ""; // Set the tokenizer to null
        return token; // Return the next token
    }
};

// The PrintWriter class is used to write output efficiently
class PrintWriter {
public:
    std::ofstream writer; // BufferedWriter for writing output

    // Constructor for PrintWriter
    PrintWriter(std::ofstream& stream) {
        writer = stream; // Create a BufferedWriter with a buffer size of 32768
    }

    // Method to print a string to the output stream
    void println(std::string str) {
        writer << str << std::endl; // Write the string to the output stream
    }

    // Method to close the output stream
    void close() {
        writer.close(); // Close the output stream
    }
};

// The main method initializes input and output streams, creates an instance of TaskD, and calls its solve method
int main(int argc, char* argv[]) {
    Main::main(argc, argv); // Call the main method of Main
    return 0; // Return 0
}

