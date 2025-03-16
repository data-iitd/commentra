#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class LightScanner {
public:
    LightScanner(std::istream &in) : input(in) {}

    std::string string() {
        std::string token;
        if (!(input >> token)) {
            throw std::runtime_error("No more tokens");
        }
        return token;
    }

private:
    std::istream &input;
};

class BUnhappyHackingABCEdit {
public:
    void solve(int testNumber, LightScanner &in, std::ostream &out) {
        // Read the input string
        std::string s = in.string();
        
        // StringBuilder equivalent in C++
        std::string d;
        
        // Iterate over each character in the input string
        for (char c : s) {
            switch (c) {
                case '0':
                    // Append '0' to the result
                    d += '0';
                    break;
                case '1':
                    // Append '1' to the result
                    d += '1';
                    break;
                case 'B':
                    // Remove the last character if the result is not empty
                    if (!d.empty()) {
                        d.pop_back();
                    }
                    break;
            }
        }
        
        // Print the result
        out << d << std::endl;
    }
};

int main() {
    // Step 1: Define the input stream and output stream
    std::istream &inputStream = std::cin;
    std::ostream &outputStream = std::cout;
    
    // Step 2: Create a LightScanner instance for reading input efficiently
    LightScanner in(inputStream);
    
    // Step 3: Create an instance of the problem solver
    BUnhappyHackingABCEdit solver;
    
    // Step 4: Solve the problem
    solver.solve(1, in, outputStream);
    
    return 0;
}

// <END-OF-CODE>
