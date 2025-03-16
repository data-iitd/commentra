#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Read an integer input which represents the number of lists to be processed
    int n;
    cin >> n;

    // Initialize an empty list to store the input lists
    vector<vector<string>> q;

    // Initialize a counter to keep track of the matching conditions
    int count = 0;

    // Loop to read 'n' lines of input and store them in the list 'q'
    for (int i = 0; i < n; i++) {
        // Read a line of input, split it into a list of strings, and append it to 'q'
        string line;
        cin >> line;
        vector<string> a = split(line);
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
            if (q[j][0] == q[k][q[k].size() - 1]) {
                // Increment the count if the condition is met
                count++;
            } else {
                // Continue to the next iteration if the condition is not met
                continue;
            }
        }
    }

    // Print the final count of matching conditions
    cout << count << endl;

    return 0;
}

