#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>

class FastScanner {
public:
    FastScanner() : buffer(std::istreambuf_iterator<char>(std::cin), std::istreambuf_iterator<char>()) {}

    int NextInt() {
        std::string token = Next();
        return std::stoi(token);
    }

    std::string Next() {
        ensureData();
        std::string token;
        for (; buffer[pos] != ' ' && buffer[pos] != '\0'; ++pos) {
            token += buffer[pos];
        }
        ++pos;
        return token;
    }

    std::string NextLine() {
        ensureData();
        std::string line;
        for (; buffer[pos] != '\n' && buffer[pos] != '\0'; ++pos) {
            line += buffer[pos];
        }
        ++pos;
        return line;
    }

private:
    std::string buffer;
    size_t pos = 0;

    void ensureData() {
        if (pos >= buffer.size()) {
            buffer.clear();
            std::getline(std::cin, buffer);
            pos = 0;
        }
    }
};

int main() {
    FastScanner fsc;
    int A = fsc.NextInt();
    int B = fsc.NextInt();
    int C = fsc.NextInt();

    if (B - A == C - B) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
