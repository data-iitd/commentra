#include <iostream> // For input and output operations
#include <vector>   // For using vectors
#include <algorithm> // For sorting and searching operations

using namespace std;

// Function to read an integer from input
int intScanner() {
    int n;
    cin >> n;
    return n;
}

// Main function
int main() {
    const int mod = 1000000007; // Modulus value
    int n = intScanner(); // Read the number of elements
    vector<int> as(n); // Vector to store the elements

    for (int i = 0; i < n; i++) {
        as[i] = intScanner(); // Read each element
    }

    // Initialize xs with the first element of as
    vector<int> xs;
    xs.push_back(as[0]);

    for (int j = 1; j < n; j++) {
        // Use lower_bound to find the position to insert the current element
        auto idx = lower_bound(xs.begin(), xs.end(), as[j]);
        if (idx == xs.end()) {
            // If the element is larger than all elements in xs, append it
            xs.push_back(as[j]);
        } else {
            // Otherwise, replace the existing element at the found position
            *idx = as[j];
        }
    }

    // Print the length of the longest increasing subsequence found
    cout << xs.size() << endl;

    return 0;
}

// <END-OF-CODE>
