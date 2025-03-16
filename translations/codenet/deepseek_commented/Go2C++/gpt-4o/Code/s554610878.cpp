#include <iostream>
#include <string>
#include <vector>
#include <cmath>

const int mod = 1e9 + 7;

// Function to get the number of days until Sunday for a given day.
int daysUntilSunday(const std::string& day) {
    std::vector<std::string> week = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    int index = -1;
    for (int i = 0; i < week.size(); ++i) {
        if (day == week[i]) {
            index = i; // Set the index of the day found in the week array.
            break;
        }
    }
    return 7 - index; // Return the number of days until Sunday.
}

int main() {
    std::string s;
    std::cin >> s; // Get the input day as a string.
    std::cout << daysUntilSunday(s) << std::endl; // Print the number of days until Sunday.
    return 0;
}

// Helper functions (not used in this specific example but included for completeness)
int abs(int a) {
    return std::abs(a);
}

int pow(int p, int q) {
    return static_cast<int>(std::pow(p, q));
}

int min(std::initializer_list<int> nums) {
    if (nums.size() == 0) {
        throw std::invalid_argument("function min() requires at least one argument.");
    }
    return *std::min_element(nums.begin(), nums.end());
}

int max(std::initializer_list<int> nums) {
    if (nums.size() == 0) {
        throw std::invalid_argument("function max() requires at least one argument.");
    }
    return *std::max_element(nums.begin(), nums.end());
}

bool strSearch(const std::vector<std::string>& a, const std::string& b) {
    return std::find(a.begin(), a.end(), b) != a.end();
}

void printIntArray(const std::vector<int>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i];
        if (i < array.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int calcMod(int x) {
    return x % mod;
}

// <END-OF-CODE>
