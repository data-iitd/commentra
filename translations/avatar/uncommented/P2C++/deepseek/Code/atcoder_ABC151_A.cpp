#include <iostream>
#include <string>
#include <vector>
#include <sstream>

bool debug = false;

void log(const std::string& text) {
    if (debug) {
        std::cout << text << std::endl;
    }
}

std::vector<std::string> parse_input(const std::string& lines_as_string = "") {
    std::vector<std::string> lines;
    if (lines_as_string.empty()) {
        debug = false;
        std::string line;
        std::getline(std::cin, line);
        lines.push_back(line);
    } else {
        debug = true;
        std::stringstream ss(lines_as_string);
        std::string line;
        while (std::getline(ss, line, '\n')) {
            if (!line.empty() && line != "\n") {
                lines.push_back(line);
            }
        }
    }
    std::vector<std::string> result;
    std::stringstream ss(lines[0]);
    std::string token;
    std::getline(ss, token, ' ');
    result.push_back(token);
    return result;
}

char solve(const char& c) {
    std::string a = "abcdefghijklmnopqrstuvwxyz";
    int i = a.find(c);
    return a[i + 1];
}

int main() {
    std::vector<std::string> result = parse_input();
    char c = result[0][0];
    char output = solve(c);
    std::cout << output << std::endl;
    return 0;
}

