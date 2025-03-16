#include <iostream>
#include <vector>
#include <algorithm>

void s() {
    // Read input as a list of integers
    std::vector<int> input_list;
    int num;
    while (std::cin >> num) {
        input_list.push_back(num);
        if (std::cin.peek() == '\n') break; // Stop reading on newline
    }

    // Sort the input list in ascending order
    std::sort(input_list.begin(), input_list.end());

    // Initialize a variable to store the result
    std::string result = "";

    // Iterate through the sorted list starting from the second element
    for (size_t i = 1; i < input_list.size(); ++i) {
        // Compare the current element with the previous one
        int current_element = input_list[i];
        int previous_element = input_list[i - 1];

        // Check if the current element is less than twice the previous element
        // and if it is not equal to the previous element
        if (current_element < previous_element * 2 && current_element != previous_element) {
            // If the condition is true, set the result to 'YES'
            result = "YES";
            // Break out of the loop since we have found the answer
            break;
        }
    }

    // Print the result
    if (result.empty()) {
        std::cout << "NO" << std::endl; // If result is still empty, print "NO"
    } else {
        std::cout << result << std::endl;
    }
}

// Main function to call s()
int main() {
    s();
    return 0;
}

// <END-OF-CODE>
