#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;  // Take an integer input representing the number of elements
    std::vector<std::string> q;  // Initialize a vector to store the elements
    int count = 0;  // Initialize a counter to keep track of valid pairs

    // Loop to take input and append to the vector `q`
    for (int i = 0; i < n; ++i) {
        std::string a;
        std::cin >> a;  // Read the input string
        q.push_back(a);  // Append the input string to the vector `q`
    }

    // Nested loop to compare each element with every other element
    for (const auto& j : q) {
        for (const auto& k : q) {
            if (&j == &k)  // Skip if the same element is compared with itself
                continue;
            if (j[0] == k.back())  // Check if the first character of `j` matches the last character of `k`
                ++count;  // Increment the counter if the condition is met
        }
    }

    std::cout << count << std::endl;  // Print the total count of valid pairs

    return 0;
}
