#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

class SimpleScanner {
public:
    SimpleScanner(std::istream& in) : in(in) {}

    char nextChar() {
        char b;
        if (!(in >> b)) {
            throw std::out_of_range("End of input");
        }
        return b;
    }

    std::string next() {
        std::string result;
        char b;
        while (in >> std::ws && in.get(b)) {
            if (isspace(b)) {
                if (!result.empty()) {
                    break;
                }
            } else {
                result += b;
            }
        }
        if (result.empty() && in.eof()) {
            throw std::out_of_range("End of input");
        }
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
};

int main() {
    SimpleScanner scanner(std::cin);
    long long r = scanner.nextInt();
    long long d = scanner.nextInt();
    long long x = scanner.nextLong();

    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        std::cout << x << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
