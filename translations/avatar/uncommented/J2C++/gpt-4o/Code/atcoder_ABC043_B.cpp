#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class LightScanner {
public:
    LightScanner(std::istream &in) : reader(in) {}

    std::string string() {
        if (tokens.empty()) {
            std::string line;
            std::getline(reader, line);
            std::istringstream iss(line);
            std::string token;
            while (iss >> token) {
                tokens.push_back(token);
            }
        }
        std::string token = tokens.front();
        tokens.erase(tokens.begin());
        return token;
    }

private:
    std::istream &reader;
    std::vector<std::string> tokens;
};

class BUnhappyHackingABCEdit {
public:
    void solve(int testNumber, LightScanner &in, std::ostream &out) {
        std::string s = in.string();
        std::string d;
        for (char c : s) {
            switch (c) {
                case '0':
                    d += "0";
                    break;
                case '1':
                    d += "1";
                    break;
                case 'B':
                    if (!d.empty()) {
                        d.pop_back();
                    }
                    break;
            }
        }
        out << d << std::endl;
    }
};

int main() {
    LightScanner in(std::cin);
    BUnhappyHackingABCEdit solver;
    solver.solve(1, in, std::cout);
    return 0;
}

// <END-OF-CODE>
