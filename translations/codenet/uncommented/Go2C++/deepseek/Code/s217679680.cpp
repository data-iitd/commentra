#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> arr;
    std::string token;
    while (std::getline(iss, token, ' ')) {
        arr.push_back(std::stoi(token));
    }
    int a = arr[0];
    int b = arr[1];
    int tap = 0;
    int consent = 1;
    while (consent < b) {
        consent = consent + a - 1;
        tap++;
    }
    std::cout << tap << std::endl;
    return 0;
}

