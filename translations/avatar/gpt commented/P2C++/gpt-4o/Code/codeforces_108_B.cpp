#include <iostream>
#include <vector>
#include <algorithm>

std::string s() {
    // Read an input line (not used in the logic)
    std::string temp;
    std::getline(std::cin, temp);
    
    // Read a line of integers and convert them to a vector of integers
    std::vector<int> a;
    int num;
    while (std::cin >> num) {
        a.push_back(num);
    }
    
    // Sort the vector of integers in ascending order
    std::sort(a.begin(), a.end());
    
    // Iterate through the sorted vector starting from the second element
    for (size_t i = 1; i < a.size(); ++i) {
        // Check if the current element is different from the previous one
        // and if it is less than double the previous element
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
            // If the condition is met, return "YES"
            return "YES";
        }
    }
    
    // If no such pair is found, return "NO"
    return "NO";
}

int main() {
    // Call the function and print the result
    std::cout << s() << std::endl;
    return 0;
}

// <END-OF-CODE>
