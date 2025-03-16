#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
    std::vector<int> na() {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::vector<int> numbers;
        int number;
        while (iss >> number) {
            numbers.push_back(number);
        }
        return numbers;
    }

    std::vector<int> a = na();
    std::sort(a.begin(), a.end());

    int x;
    std::cin >> x;

    int ans = 0;

    if (a[0] > x) {
        std::cout << 0 << std::endl;
        return 0;
    }

    for (int i : a) {
        if (i > x) {
            x = 0;
            break;
        }
        x -= i;
        ans += 1;
    }

    if (x != 0) {
        ans -= 1;
    }

    std::cout << ans << std::endl;

    return 0;
}
