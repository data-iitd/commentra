#include <iostream>
#include <sstream>
#include <string>
#include <limits>

class SimpleScanner {
private:
    std::istream& in;
    std::string buffer;
    std::string::size_type pos;
    bool eof;

public:
    SimpleScanner(std::istream& is) : in(is), buffer(), pos(0), eof(false) {}

    char read() {
        if (pos >= buffer.size()) {
            if (std::getline(in, buffer).eof()) {
                eof = true;
                return '\0'; // End of file character
            }
            pos = 0;
        }
        return buffer[pos++];
    }

    void checkEof() {
        if (eof) throw std::out_of_range("End of input");
    }

    char nextChar() {
        checkEof();
        char c = read();
        checkEof();
        return c;
    }

    std::string next() {
        std::stringstream ss;
        char c;
        do {
            c = read();
            checkEof();
            ss << c;
        } while (!eof);
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

