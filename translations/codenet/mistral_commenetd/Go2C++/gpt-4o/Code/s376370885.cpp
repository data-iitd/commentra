// by syu
#include <iostream> // Include iostream for input and output
#include <sstream>  // Include sstream for string stream
#include <string>   // Include string for string manipulation

// Custom scanner class to handle input
class Scanner {
public:
    Scanner(std::istream &input) : stream(input) {}

    // Read an integer from the input
    int Int() {
        int value;
        stream >> value; // Read an integer from the stream
        return value; // Return the read integer
    }

private:
    std::istream &stream; // Reference to the input stream
};

// Print a line to the console with the given arguments
template<typename... Args>
void Pln(Args... args) {
    (std::cout << ... << args) << std::endl; // Print all arguments followed by a newline
}

// Entry point of the program
int main() {
    Scanner in(std::cin); // Create a Scanner instance for standard input
    // Read two integers n and k from standard input
    int n = in.Int();
    int k = in.Int();
    
    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0 to the console
        Pln(0);
    } else {
        // If n is not divisible by k, print 1 to the console
        Pln(1);
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
