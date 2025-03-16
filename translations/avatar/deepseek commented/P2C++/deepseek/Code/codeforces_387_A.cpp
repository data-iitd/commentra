#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string time1, time2;
    std::cin >> time1 >> time2;

    int h1, m1, h2, m2;
    h1 = std::stoi(time1.substr(0, 2));
    m1 = std::stoi(time1.substr(3, 2));
    h2 = std::stoi(time2.substr(0, 2));
    m2 = std::stoi(time2.substr(3, 2));

    m1 += h1 * 60;
    m2 += h2 * 60;

    int diff = m1 - m2;
    diff = diff % 1440;

    std::ostringstream oss;
    oss << (diff / 60) << ":" << (diff % 60);
    std::string result = oss.str();

    if (result.length() < 5) {
        result = "0" + result;
    }

    std::cout << result << std::endl;

    return 0;
}
