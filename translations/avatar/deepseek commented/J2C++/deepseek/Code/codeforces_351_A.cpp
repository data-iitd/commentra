#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    int n;
    std::string line;
    std::getline(std::cin, line);
    n = std::stoi(line);

    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<double> arr;
    double num;
    double sum_before = 0, sum = 0;
    int non_int = 0;

    while (iss >> num) {
        sum_before += num;
        if (std::floor(num) != num) non_int++;
        sum += std::floor(num);
        arr.push_back(num);
    }

    double max_sum = std::min(n, non_int) + sum;
    double min_sum = std::max(0, non_int - n) + sum;
    double ans;

    if (min_sum > sum_before)
        ans = min_sum - sum_before;
    else if (max_sum < sum_before)
        ans = sum_before - max_sum;
    else {
        double x = sum_before - std::floor(sum_before);
        ans = std::min(1 - x, x);
    }

    std::cout << std::fixed << std::setprecision(3) << ans << std::endl;

    return 0;
}
