#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    std::string line;
    std::getline(std::cin, line); // To consume the newline character
    std::getline(std::cin, line);
    std::stringstream ss(line);
    for (int i = 0; i < n; ++i) {
        ss >> arr[i];
    }

    if (arr[0] > 15) {
        std::cout << 15 << std::endl;
    } else {
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i-1] > 15) {
                std::cout << arr[i-1] + 15 << std::endl;
                break;
            }
        }
        if (arr[n-1] == 90 || arr[n-1] + 15 >= 90) {
            std::cout << 90 << std::endl;
        } else {
            std::cout << arr[n-1] + 15 << std::endl;
        }
    }

    return 0;
}

