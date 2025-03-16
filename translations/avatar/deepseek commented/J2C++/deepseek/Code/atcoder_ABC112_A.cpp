#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib> // For std::atoi

class Main {
private:
    static std::istream* inputStream;

public:
    static void main(int argc, char* argv[]) {
        // Reading the number of inputs
        int n = std::stoi(read(1)[0]);

        // Processing the input based on the value of n
        if (n == 1) {
            // Outputting "Hello World" if n is 1
            std::cout << "Hello World" << std::endl;
        } else {
            // Reading two strings and calculating their sum if n is not 1
            std::vector<std::string> strs = read(2);
            std::cout << std::atoi(strs[0].c_str()) + std::atoi(strs[1].c_str()) << std::endl;
        }
    }

    // Method to read input from the standard input stream
    static std::vector<std::string> read(int len) {
        std::vector<std::string> strList;
        std::string line;
        for (int i = 0; i < len; ++i) {
            std::getline(*inputStream, line);
            strList.push_back(line);
        }
        return strList;
    }

    // Method to close the input stream if it is open
    static void close() {
        if (inputStream != &std::cin) {
            delete inputStream;
            inputStream = &std::cin;
        }
    }
};

std::istream* Main::inputStream = &std::cin;

int main(int argc, char* argv[]) {
    Main::main(argc, argv);
    Main::close();
    return 0;
}

