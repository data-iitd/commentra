#include <iostream> // Include necessary header for input/output operations
#include <sstream>  // Include stringstream for efficient string handling
#include <stdexcept> // Include stdexcept for exception handling

class SimpleScanner {
public:
    SimpleScanner(std::istream &in) : in(in) {}

    // Method to read the next integer
    int nextInt() {
        int value;
        if (!(in >> value)) {
            throw std::runtime_error("No more integers available");
        }
        return value;
    }

    // Method to read the next long integer
    long long nextLong() {
        long long value;
        if (!(in >> value)) {
            throw std::runtime_error("No more long integers available");
        }
        return value;
    }

private:
    std::istream &in; // The input stream to read from
};

int main() {
    // Create a SimpleScanner instance to read from standard input
    SimpleScanner scanner(std::cin);
    // Create an output stream to write to standard output
    std::ostream &writer = std::cout;

    // Read three integers from the input
    int r = scanner.nextInt();
    int d = scanner.nextInt();
    long long x = scanner.nextLong();

    // Perform the calculation in a loop and print the result 10 times
    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        writer << x << std::endl;
    }

    return 0; // Return success
}

// <END-OF-CODE>
