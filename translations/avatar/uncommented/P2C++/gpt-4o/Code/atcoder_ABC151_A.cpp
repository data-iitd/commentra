#include <iostream>
#include <string>

bool debug = false;

void log(const std::string& text) {
    if (debug) {
        std::cout << text << std::endl;
    }
}

std::string parse_input(std::string lines_as_string = "") {
    std::string c;
    if (lines_as_string.empty()) {
        debug = false;
        std::cin >> c;
    } else {
        debug = true;
        size_t pos = lines_as_string.find('\n');
        if (pos != std::string::npos) {
            c = lines_as_string.substr(0, pos);
        }
    }
    return c;
}

char solve(char c) {
    std::string a = "abcdefghijklmnopqrstuvwxyz";
    size_t i = a.find(c);
    return a[i + 1];
}

int main() {
    std::string input = parse_input();
    char result = solve(input[0]);
    std::cout << result << std::endl;
    return 0;
}

// <END-OF-CODE>
