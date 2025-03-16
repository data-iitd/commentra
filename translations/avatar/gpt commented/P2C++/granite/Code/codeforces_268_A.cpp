
#include <iostream>
#include <vector>
#include <string>

int main() {
    // Read an integer input which represents the number of lists to be processed
    int n;
    std::cin >> n;

    // Initialize an empty vector to store the input lists
    std::vector<std::vector<std::string>> q;

    // Initialize a counter to keep track of the matching conditions
    int count = 0;

    // Loop to read 'n' lines of input and store them in the vector 'q'
    for (int i = 0; i < n; i++) {
        // Read a line of input, split it into a vector of strings, and append it to 'q'
        std::vector<std::string> a;
        std::string input;
        std::getline(std::cin, input);
        std::stringstream ss(input);
        std::string token;
        while (std::getline(ss, token,'')) {
            a.push_back(token);
        }
        q.push_back(a);
    }

    // Nested loop to compare each list in 'q' with every other list
    for (int j = 0; j < q.size(); j++) {
        for (int k = 0; k < q.size(); k++) {
            // Skip comparison if both lists are the same
            if (k == j) {
                continue;
            }
            // Check if the first element of list 'j' matches the last element of list 'k'
            else if (q[j][0] == q[k][q[k].size() - 1]) {
                // Increment the count if the condition is met
                count++;
            }
            else {
                // Continue to the next iteration if the condition is not met
                continue;
            }
        }
    }

    // Print the final count of matching conditions
    std::cout << count << std::endl;

    return 0;
}
