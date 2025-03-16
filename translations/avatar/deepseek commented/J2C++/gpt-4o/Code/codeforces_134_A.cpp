#include <iostream> // Include necessary header for input/output
#include <vector>   // Include vector header for dynamic array
#include <sstream>  // Include stringstream for output formatting

using namespace std;

int main() {
    int n;
    cin >> n; // Read the size of the array
    vector<int> arr(n); // Create a vector of size n
    int sum = 0; // Initialize sum to 0

    // Read n integers from the user and store them in the vector arr, while updating the sum
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int c = 0; // Initialize count of valid elements to remove
    stringstream ss; // Create a stringstream to build the output string

    // Iterate through the vector arr to find elements that can be removed
    for (int i = 0; i < n; i++) {
        // Check if removing the current element keeps the average unchanged
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++; // Increment the count
            ss << (i + 1) << " "; // Append the index (plus one) to the stringstream
        }
    }

    // Print the count of valid elements and the indices of these elements
    cout << c << endl;
    cout << ss.str() << endl;

    return 0;
}

// <END-OF-CODE>
