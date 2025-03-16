#include <iostream>
#include <vector>
#include <string>

int main() {
    // Read an integer input which represents the number of lists to be processed
    int n;
    std::cin >> n;

    // Initialize a vector to store the input lists
    std::vector<std::vector<std::string>> q;

    // Initialize a counter to keep track of the matching conditions
    int count = 0;

    // Loop to read 'n' lines of input and store them in the vector 'q'
    std::cin.ignore(); // To ignore the newline character after reading n
    for (int i = 0; i < n; i++) {
        std::string line;
        std::getline(std::cin, line);
        std::vector<std::string> a;
        std::string word;
        std::istringstream iss(line);
        while (iss >> word) {
            a.push_back(word);
        }
        q.push_back(a);
    }

    // Nested loop to compare each list in 'q' with every other list
    for (const auto& j : q) {
        for (const auto& k : q) {
            // Skip comparison if both lists are the same
            if (k == j) {
                continue;
            }
            // Check if the first element of list 'j' matches the last element of list 'k'
            if (j[0] == k.back()) {
                // Increment the count if the condition is met
                count++;
            }
        }
    }

    // Print the final count of matching conditions
    std::cout << count << std::endl;

    return 0;
}

// <END-OF-CODE>
