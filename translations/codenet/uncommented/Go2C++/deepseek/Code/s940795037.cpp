#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

class Scanner {
public:
    Scanner() : buffer(std::istreambuf_iterator<char>(std::cin)), end(buffer.base()) {}

    std::string next() {
        skip();
        std::string result;
        while (pos < end && *pos != ' ') {
            result += *pos++;
        }
        pos++; // skip space
        return result;
    }

    std::string nextLine() {
        skip();
        std::string result(pos, end);
        pos = end;
        return result;
    }

    int nextInt() {
        return std::stoi(next());
    }

    std::vector<int> nextIntArray() {
        std::vector<int> result;
        std::string token;
        while (std::getline(std::cin, token, ' ')) {
            result.push_back(std::stoi(token));
        }
        return result;
    }

    std::map<int, bool> nextMap() {
        std::map<int, bool> result;
        std::string token;
        while (std::getline(std::cin, token, ' ')) {
            result[std::stoi(token)] = true;
        }
        return result;
    }

private:
    void skip() {
        while (pos < end && (*pos == ' ' || *pos == '\n')) {
            pos++;
        }
    }

    std::istreambuf_iterator<char> buffer;
    char* pos = buffer.base();
    char* end;
};

int main() {
    Scanner sc;
    int n = sc.nextInt();
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int tmp = sc.nextInt();
        ans += 1.0 / tmp;
    }
    std::cout << std::fixed << std::setprecision(10) << 1.0 / ans << std::endl;
}

