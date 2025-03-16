#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

class Scanner {
public:
    Scanner() : buffer(std::istreambuf_iterator<char>(std::cin), {}) {}

    std::string Next() {
        skipWhitespace();
        std::string result;
        while (pos < buffer.size() && buffer[pos] != ' ') {
            result += buffer[pos++];
        }
        pos++; // Skip the space
        return result;
    }

    std::string NextLine() {
        skipWhitespace();
        std::string result;
        while (pos < buffer.size() && buffer[pos] != '\n') {
            result += buffer[pos++];
        }
        pos++; // Skip the newline
        return result;
    }

    int NextInt() {
        return std::stoi(Next());
    }

    int64_t NextInt64() {
        return std::stoll(Next());
    }

    double NextFloat() {
        return std::stod(Next());
    }

    std::vector<int> NextIntArray() {
        std::string line = NextLine();
        std::vector<int> result;
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            result.push_back(num);
        }
        return result;
    }

    std::vector<int64_t> NextInt64Array() {
        std::string line = NextLine();
        std::vector<int64_t> result;
        std::istringstream iss(line);
        int64_t num;
        while (iss >> num) {
            result.push_back(num);
        }
        return result;
    }

    std::map<int, bool> NextMap() {
        std::string line = NextLine();
        std::map<int, bool> result;
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            result[num] = true;
        }
        return result;
    }

private:
    std::string buffer;
    size_t pos = 0;

    void skipWhitespace() {
        while (pos < buffer.size() && std::isspace(buffer[pos])) {
            pos++;
        }
    }
};

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    Scanner sc;
    int H = sc.NextInt(), W = sc.NextInt(), N = sc.NextInt();
    int A = max(H, W);
    std::cout << (N + A - 1) / A << std::endl;
    return 0;
}

