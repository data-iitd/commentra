#include <iostream> // For input and output
#include <vector>   // For using vectors
#include <algorithm> // For sorting

using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of elements
    vector<long long> ans(n); // Initialize vector to store long integers

    // Populate the vector with input values
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }

    // Sort the vector in ascending order
    sort(ans.begin(), ans.end());

    // Initialize count with the largest element in the vector
    long long count = ans[n - 1];

    // Iterate through the vector from the second-to-last element to the first
    for (int i = n - 2; i >= 0; i--) {
        if (ans[i] < ans[i + 1]) {
            count += ans[i]; // Add the current element to count if it's less than the next element
        } else {
            while (ans[i] >= ans[i + 1]) {
                ans[i]--; // Decrease the current element until it's less than the next element
            }
            if (ans[i] > 0) {
                count += ans[i]; // Add the adjusted current element to count
            }
        }
    }

    // Print the final count
    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
