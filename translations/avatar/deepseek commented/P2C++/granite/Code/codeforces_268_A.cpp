

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;  // Take an integer input representing the number of elements
    vector<string> q;  // Initialize a vector of strings to store the elements
    int count = 0;  // Initialize a counter to keep track of valid pairs

    // Loop to take input and append to the vector `q`
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;  // Take a string input
        q.push_back(a);  // Append the input string to the vector `q`
    }

    // Nested loop to compare each element with every other element
    for (int j = 0; j < q.size(); j++) {
        for (int k = 0; k < q.size(); k++) {
            if (k == j) {  // Skip if the same element is compared with itself
                continue;
            } else if (q[j][0] == q[k][q[k].size() - 1]) {  // Check if the first character of `q[j]` matches the last character of `q[k]`
                count++;  // Increment the counter if the condition is met
            } else {
                continue;
            }
        }
    }

    cout << count << endl;  // Print the total count of valid pairs

    return 0;
}
