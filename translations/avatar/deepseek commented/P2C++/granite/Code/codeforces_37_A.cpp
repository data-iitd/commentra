

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;  // Read the number of elements
    vector<int> l(n);  // Initialize the vector with n elements
    for (int i = 0; i < n; i++) {
        cin >> l[i];  // Read the elements into the vector
    }

    // Sort the vector
    sort(l.begin(), l.end());

    int high = 1;
    int tower = n;
    int maximum = 1;

    // Loop through the sorted vector
    for (int i = 1; i < n; i++) {
        if (l[i] == l[i - 1]) {  // Check if the current element is equal to the previous element
            tower--;  // Decrement the tower count
            high++;  // Increment the high count
        } else {
            if (high > maximum) {  // Check if the current high is greater than the maximum
                maximum = high;  // Update the maximum
            }
            high = 1;  // Reset high to 1
        }
    }

    if (high > maximum) {  // Check if the final high is greater than the maximum
        maximum = high;  // Update the maximum
    }

    // Print the result
    cout << maximum << " " << tower << endl;

    return 0;
}
