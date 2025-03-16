#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a function named s that takes no arguments
void s() {

    // Read input as a list of integers
    vector<int> input_list;
    int num;
    while (cin >> num) {
        input_list.push_back(num);
    }

    // Sort the input list in ascending order
    sort(input_list.begin(), input_list.end());

    // Initialize a variable to store the result
    string result = "NO";

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
    cout << result << endl;
}

int main() {
    s();
    return 0;
}

