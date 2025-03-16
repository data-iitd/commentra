#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> p;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ' ')) {
        p.push_back(token);
    }

    int x1 = std::stoi(p[0]);
    int y1 = std::stoi(p[1]);
    int x2 = std::stoi(p[2]);
    int y2 = std::stoi(p[3]);

    int DIF1 = x2 - x1;
    int DIF2 = y2 - y1;

    int x3 = x2 - DIF2;
    int y3 = y2 + DIF1;

    int x4 = x1 - DIF2;
    int y4 = y1 + DIF1;

    std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;

    return 0;
}
