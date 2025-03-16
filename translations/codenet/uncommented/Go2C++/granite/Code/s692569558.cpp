
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::string ds;
    std::getline(std::cin, ds);
    std::getline(std::cin, ds);

    std::vector<int> dn;
    std::stringstream ss(ds);
    std::string d;
    while (std::getline(ss, d,'')) {
        dn.push_back(std::stoi(d));
    }

    int sum = 0;
    for (int i = 0; i < dn.size(); i++) {
        for (int j = i + 1; j < dn.size(); j++) {
            sum += dn[i] * dn[j];
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
