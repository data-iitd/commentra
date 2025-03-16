#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

void Run(std::istream &in, std::ostream &out) {
    int N, D;
    in >> N >> D;

    int count = 0;
    for (int i = 0; i < N; ++i) {
        int x, y;
        in >> x >> y;
        double d = std::sqrt(x * x + y * y);
        if (D >= d) {
            count++;
        }
    }
    out << count << std::endl;
}

int main() {
    Run(std::cin, std::cout);
    return 0;
}

// <END-OF-CODE>
