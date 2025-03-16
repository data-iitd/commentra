#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::pair<int, int>> menu;
    for (int i = 0; i < 5; ++i) {
        std::string m;
        std::cin >> m;
        int e = m.back() - '0'; // Extracting the last digit and converting it to an integer
        if (e == 0) {
            e = 10; // If the last digit is 0, change it to 10
        }
        menu.push_back({std::stoi(m), e}); // Appending the input value and the processed last digit as a pair to the menu vector
    }
    std::sort(menu.begin(), menu.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second; // Sorting the menu vector based on the last digit
    });
    int ans = 0;
    for (int i = 1; i < menu.size(); ++i) {
        ans += std::ceil(static_cast<double>(menu[i].first) / 10) * 10; // Calculating the sum of the ceiling of each element divided by 10, multiplied by 10
    }
    std::cout << ans + menu[0].first << std::endl; // Printing the sum of the first element and the calculated ans
    return 0;
}

