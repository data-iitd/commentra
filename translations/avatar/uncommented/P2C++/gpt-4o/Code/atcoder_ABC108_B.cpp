#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> p;
    int num;

    while (iss >> num) {
        p.push_back(num);
    }

    int x1 = p[0];
    int y1 = p[1];
    int x2 = p[2];
    int y2 = p[3];

    int DIF1 = x2 - x1;
    int DIF2 = y2 - y1;

    int x3 = x2 - DIF2;
    int y3 = y2 + DIF1;
    int x4 = x1 - DIF2;
    int y4 = y1 + DIF1;

    std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;

    return 0;
}

// <END-OF-CODE>
