#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>

int main() {
    // Read an integer input from the user
    auto num_inp = []() {
        int input;
        std::cin >> input;
        return input;
    };

    // Read a list of integers from the input
    auto arr_inp = []() {
        std::vector<int> inputs;
        std::string line;
        std::getline(std::cin, line); // To consume the newline character
        std::getline(std::cin, line);
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            inputs.push_back(num);
        }
        return inputs;
    };

    // Read a map of integers from the input
    auto sp_inp = []() {
        std::map<int, int> inputs;
        std::string line;
        std::getline(std::cin, line); // To consume the newline character
        std::getline(std::cin, line);
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            inputs[num]++;
        }
        return inputs;
    };

    // Read the entire input, split the second line into a list of integers, and sort them
    std::vector<int> a;
    std::string line;
    std::getline(std::cin, line); // To consume the newline character
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int num;
    while (iss >> num) {
        a.push_back(num);
    }
    std::sort(a.begin(), a.end());

    // Print the first element of the sorted list if it is divisible by any other element in the list, otherwise print -1
    bool divisible = false;
    for (int x : a) {
        if (x != a[0] && a[0] % x == 0) {
            divisible = true;
            break;
        }
    }
    std::cout << (divisible ? a[0] : -1) << std::endl;

    return 0;
}
