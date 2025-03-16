#include <iostream>
#include <vector>
#include <string>

int main() {
    // Ask user for the number of arrays (n) they want to input
    int n;
    std::cin >> n;

    // Create a vector of vectors to store these arrays
    std::vector<std::vector<std::string>> q(n);

    // Use a for loop to iterate through the range of 'n' and for each iteration,
    // ask the user for an array (a) and append it to our vector 'q'
    for (int i = 0; i < n; ++i) {
        std::string input;
        std::cin >> input;
        q[i].push_back(input);
        while (std::cin.peek() != '\n' && std::cin >> input) {
            q[i].push_back(input);
        }
    }

    // Initialize count variable
    int count = 0;

    // Use another for loop to iterate through each array in our vector 'q'
    for (const auto& j : q) {
        // For each array 'j', use another for loop to iterate through every other array in our vector 'q'
        for (const auto& k : q) {
            // Exclude the current array 'j' from comparison using 'continue' statement if they are the same
            if (k == j) {
                continue;
            }
            // Check if the last element of the second array 'k' matches the first element of the first array 'j'
            if (j[0] == k.back()) {
                // If it does, increment our 'count' variable
                count++;
            }
        }
    }

    // Finally, print out the value of our 'count' variable
    std::cout << count << std::endl;

    return 0;
}

// <END-OF-CODE>
