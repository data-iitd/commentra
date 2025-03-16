#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;  // Take an integer input representing the number of elements
    vector<vector<string>> q;  // Initialize a 2D vector to store the elements
    int count = 0;  // Initialize a counter to keep track of valid pairs

    // Loop to take input and append to the vector `q`
    for (int i = 0; i < n; i++) {
        vector<string> a;  // Temporary vector to store the split input
        string input;
        cin >> input;  // Read the input as a single string
        a.push_back(input);  // Append the input to the temporary vector
        q.push_back(a);  // Append the temporary vector to the list `q`
    }

    // Nested loop to compare each element with every other element
    for (const auto& j : q) {
        for (const auto& k : q) {
            if (k == j) {  // Skip if the same element is compared with itself
                continue;
            } else if (j[0] == k.back()) {  // Check if the first character of `j` matches the last character of `k`
                count++;  // Increment the counter if the condition is met
            } else {
                continue;
            }
        }
    }

    cout << count << endl;  // Print the total count of valid pairs
    return 0;
}  // <END-OF-CODE>
