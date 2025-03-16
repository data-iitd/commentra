#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <limits>

class SimpleScanner {
private:
    std::istream* in;
    std::string buffer;
    std::string::iterator it;
    bool eof;

public:
    SimpleScanner(std::istream& is) : in(&is), buffer(), it(buffer.begin()), eof(false) {}

    char read() {
        if (it == buffer.end()) {
            buffer.clear();
            std::getline(*in, buffer);
            if (buffer.empty()) {
                eof = true;
                return '\0';
            }
            it = buffer.begin();
        }
        return *it++;
    }

    void checkEof() {
        if (eof) throw std::out_of_range("End of input");
    }

    char nextChar() {
        checkEof();
        char b = read();
        checkEof();
        return b;
    }

    std::string next() {
        char b;
        do {
            b = read();
            checkEof();
        } while (std::isspace(b));
        std::stringstream ss;
        do {
            ss << b;
            b = read();
        } while (!eof && !std::isspace(b));
        return ss.str();
    }

    int nextInt() {
        return std::stoi(next());
    }

    long nextLong() {
        return std::stol(next());
    }

    double nextDouble() {
        return std::stod(next());
    }
};

int main() {
    SimpleScanner scanner(std::cin);
    std::ostream& out = std::cout;

    int r = scanner.nextInt();
    int d = scanner.nextInt();
    long x = scanner.nextLong();

    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        out << x << std::endl;
    }

    return 0;
}

