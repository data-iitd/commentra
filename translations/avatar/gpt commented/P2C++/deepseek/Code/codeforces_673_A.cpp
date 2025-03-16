#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // To ignore the newline character after the integer input

    std::vector<int> arr(n);
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);

    for (int i = 0; i < n; ++i) {
        iss >> arr[i];
    }

    if (arr[0] > 15) {
        std::cout << 15 << std::endl;
    } else {
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i - 1] > 15) {
                std::cout << arr[i - 1] + 15 << std::endl;
                break;
            }
        }
        if (arr[n - 1] == 90 || arr[n - 1] + 15 >= 90) {
            std::cout << 90 << std::endl;
        } else {
            std::cout << arr[n - 1] + 15 << std::endl;
        }
    }

    return 0;
}

