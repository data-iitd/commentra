#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

class SimpleScanner {
public:
    SimpleScanner(std::istream& in) : in(in) {}

    char nextChar() {
        checkEof();
        char b = read();
        checkEof();
        return b;
    }

    std::string next() {
        char b;
        // Skip any whitespace characters
        do {
            b = read();
            checkEof();
        } while (isspace(b));

        std::string result;
        // Append characters until a whitespace or EOF is encountered
        do {
            result += b;
            b = read();
        } while (!eof && !isspace(b));

        return result;
    }

    int nextInt() {
        return std::stoi(next());
    }

    long long nextLong() {
        return std::stoll(next());
    }

    double nextDouble() {
        return std::stod(next());
    }

private:
    std::istream& in;
    bool eof = false;

    char read() {
        char b;
        if (in.get(b)) {
            return b;
        } else {
            eof = true;
            return '\0';
        }
    }

    void checkEof() {
        if (eof) throw std::out_of_range("End of input reached");
    }
};

int main() {
    SimpleScanner scanner(std::cin);
    long long x;
    int r = scanner.nextInt();
    int d = scanner.nextInt();
    x = scanner.nextLong();

    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        std::cout << x << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
