#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> ABC;
    std::stringstream ss(input);
    int num;

    while (ss >> num) {
        ABC.push_back(num);
    }

    // Check if the vector contains exactly two 5s
    int count_5 = 0;
    for (int i = 0; i < ABC.size(); ++i) {
        if (ABC[i] == 5) {
            ++count_5;
        }
    }

    // Check if the sum of the elements in ABC is 17
    int sum_ABC = 0;
    for (int i = 0; i < ABC.size(); ++i) {
        sum_ABC += ABC[i];
    }

    if (count_5 == 2 && sum_ABC == 17) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
