#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

class SimpleScanner {
private:
    static const int BUFFER_SIZE = 10240;
    std::istream* in;
    char buffer[BUFFER_SIZE];
    int bufferSize;
    int bufferPos;
    bool eof;

public:
    SimpleScanner(std::istream& in) : in(&in), bufferSize(0), bufferPos(0), eof(false) {}

    char read() {
        if (bufferPos >= bufferSize) {
            bufferSize = in->read(buffer, BUFFER_SIZE).gcount();
            bufferPos = 0;
            if (bufferSize <= 0) {
                eof = true;
                return '\0';
            }
        }
        return buffer[bufferPos++];
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
        } while (isspace(b));
        std::stringstream sb;
        do {
            sb << b;
            b = read();
        } while (!eof && !isspace(b));
        return sb.str();
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

