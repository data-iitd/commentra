#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::string getNextString(std::istream &in) {
    std::string s;
    in >> s;
    return s;
}

int getNextInt(std::istream &in) {
    return std::stoi(getNextString(in));
}

int64_t getNextInt64(std::istream &in) {
    return std::stoll(getNextString(in));
}

uint64_t getNextUint64(std::istream &in) {
    return std::stoull(getNextString(in));
}

double getNextFloat64(std::istream &in) {
    return std::stod(getNextString(in));
}

int main(int argc, char *argv[]) {
    std::istream *input = &std::cin;
    std::ostream *output = &std::cout;

    if (argc > 1) {
        input = new std::ifstream(argv[1]);
        if (argc > 2) {
            output = new std::ofstream(argv[2]);
        }
    }

    int n = getNextInt(*input);
    std::string ans = "second";

    for (int i = 0; i < n; i++) {
        int a = getNextInt(*input);
        if (a % 2 == 1) {
            ans = "first";
            break;
        }
    }

    *output << ans << std::endl;

    if (input != &std::cin) {
        delete input;
    }
    if (output != &std::cout) {
        delete output;
    }

    return 0;
}

// <END-OF-CODE>
