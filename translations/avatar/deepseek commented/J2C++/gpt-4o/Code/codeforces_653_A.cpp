#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int n; // Number of integers
    std::cin >> n; // Read the number of integers
    std::vector<int> a; // Create a vector to store the integers

    for (int i = 0; i < n; i++) {
        int value; // Variable to hold each integer value
        std::cin >> value; // Read each integer value
        a.push_back(value); // Add the value to the vector
    }

    // Remove duplicates and sort the vector
    std::set<int> unique_values(a.begin(), a.end());
    a.assign(unique_values.begin(), unique_values.end());
    std::sort(a.begin(), a.end());

    bool found = false; // Initialize a flag to check for consecutive integers
    for (size_t i = 0; i < a.size(); i++) {
        if (i + 2 < a.size()) {
            if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
                found = true; // Set the flag if three consecutive integers are found
                break; // No need to check further
            }
        }
    }

    std::cout << (found ? "YES" : "NO") << std::endl; // Print "YES" if consecutive integers are found, otherwise print "NO"
    return 0;
}

// <END-OF-CODE>
