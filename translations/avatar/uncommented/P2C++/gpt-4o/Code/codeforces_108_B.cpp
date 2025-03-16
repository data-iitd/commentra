#include <iostream>
#include <vector>
#include <algorithm>

std::string s() {
    std::string temp;
    std::getline(std::cin, temp); // Read the first line (not used)
    int n;
    std::cin >> n; // Read the number of elements
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i]; // Read the elements into the vector
    }
    std::sort(a.begin(), a.end()); // Sort the vector

    for (int i = 1; i < a.size(); ++i) {
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
            return "YES"; // Return "YES" if the condition is met
        }
    }
    return "NO"; // Return "NO" if no conditions are met
}

int main() {
    std::cout << s() << std::endl; // Call the function and print the result
    return 0;
}

// <END-OF-CODE>
