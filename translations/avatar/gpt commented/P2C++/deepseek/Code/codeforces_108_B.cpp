#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read an input line (not used in the logic)
    std::string line;
    std::getline(std::cin, line);
    
    // Read a line of integers, split by spaces, and convert them to a vector of integers
    std::vector<int> a;
    std::string num;
    std::getline(std::cin, num);
    std::stringstream ss(num);
    int number;
    while (ss >> number) {
        a.push_back(number);
    }
    
    // Sort the vector of integers in ascending order
    std::sort(a.begin(), a.end());
    
    // Iterate through the sorted vector starting from the second element
    for (size_t i = 1; i < a.size(); ++i) {
        // Check if the current element is different from the previous one
        // and if it is less than double the previous element
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
            // If the condition is met, print 'YES' and return 0
            std::cout << "YES" << std::endl;
            return 0;
        }
    }
    
    // If no such pair is found, print 'NO'
    std::cout << "NO" << std::endl;
    return 0;
}
