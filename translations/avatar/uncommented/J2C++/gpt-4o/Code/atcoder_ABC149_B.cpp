#include <iostream>
#include <sstream>
#include <string>

class Main {
public:
    long long A, B, K;
    long long x, y;

    Main(std::istream& in) {
        std::string line;
        std::getline(in, line);
        std::istringstream iss(line);
        iss >> A >> B >> K;
    }

    void calc() {
        x = A;
        y = B;
        x = A - K;
        if (x < 0) {
            y = B + x;
            x = 0;
            if (y < 0) {
                y = 0;
            }
        }
    }

    void showResult() {
        std::cout << x << " " << y << std::endl;
    }
};

int main() {
    Main ins(std::cin);
    ins.calc();
    ins.showResult();
    return 0;
}

// <END-OF-CODE>
