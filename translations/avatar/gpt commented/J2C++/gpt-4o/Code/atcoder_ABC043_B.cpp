#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class LightScanner {
public:
    LightScanner(std::istream &in) : reader(in) {}

    std::string string() {
        if (!(reader >> token)) {
            throw std::runtime_error("No more tokens");
        }
        return token;
    }

private:
    std::istream &reader;
    std::string token;
};

class BUnhappyHackingABCEdit {
public:
    void solve(int testNumber, LightScanner &in, std::ostream &out) {
        // Read the input string
        std::string s = in.string();
        std::string d;

        // Process each character in the input string
        for (char c : s) {
            switch (c) {
                case '0':
                    // Append '0' to the output
                    d += '0';
                    break;
                case '1':
                    // Append '1' to the output
                    d += '1';
                    break;
                case 'B':
                    // Handle the 'B' character by removing the last character if possible
                    if (!d.empty()) {
                        d.pop_back(); // Remove the last character
                    }
                    break;
            }
        }
        // Output the final result
        out << d << std::endl;
    }
};

int main() {
    // Set up input and output streams
    std::istream &inputStream = std::cin;
    std::ostream &outputStream = std::cout;

    // Initialize the LightScanner for reading input
    LightScanner in(inputStream);

    // Create an instance of the problem solver
    BUnhappyHackingABCEdit solver;

    // Solve the problem for the first test case
    solver.solve(1, in, outputStream);

    return 0;
}

// <END-OF-CODE>
