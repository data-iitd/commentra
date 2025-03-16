#include <iostream>
#include <vector>
#include <algorithm>

std::string s() {
    // Take input from the user
    std::string temp;
    std::getline(std::cin, temp); // Read the first line (not used)
    
    // Read the input, split it into a vector of integers, and store it in 'a'
    std::vector<int> a;
    int num;
    while (std::cin >> num) {
        a.push_back(num);
    }

    // Sort the vector 'a'
    std::sort(a.begin(), a.end());

    // Iterate through the sorted vector starting from the second element
    for (size_t i = 1; i < a.size(); ++i) {
        // Check if the current element is not equal to the previous element
        // and if the current element is less than twice the previous element
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
            // If the condition is met, return "YES"
            return "YES";
        }
    }
    // If the loop completes without finding a match, return "NO"
    return "NO";
}

int main() {
    // Print the result returned by the function 's()'
    std::cout << s() << std::endl;
    return 0;
}

// <END-OF-CODE>
