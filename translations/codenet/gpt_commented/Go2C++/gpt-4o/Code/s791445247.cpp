// by syu
#include <iostream> // For standard I/O
#include <sstream>  // For string stream
#include <string>   // For string manipulation

// Function to read an integer from input
int readInt() {
    std::string input;
    std::getline(std::cin, input); // Read a line from standard input
    return std::stoi(input); // Convert the string to an integer
}

int main() {
    // Read two integers n and k from input
    int n = readInt();
    int k = readInt();
    
    // Check if n is divisible by k
    if (n % k == 0) {
        // If divisible, print 0
        std::cout << 0 << std::endl;
    } else {
        // If not divisible, print 1
        std::cout << 1 << std::endl;
    }

    return 0; // Return success
}

// <END-OF-CODE>
