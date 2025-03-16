
#include <iostream> // Importing the necessary package for input
#include <vector> // Importing the necessary package for arrays

using namespace std; // Using the standard namespace

int main() {
    int n; // Declare and initialize the size of the array
    cin >> n; // Read the size of the array from the user

    vector<int> arr(n); // Create a vector of size n to store the array elements
    int sum = 0; // Initialize sum to 0

    // Read n integers from the user and store them in the vector arr, while updating the sum
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int c = 0; // Initialize count of valid elements to remove
    stringstream sb; // Create a stringstream to build the output string

    // Iterate through the vector arr to find elements that can be removed
    for (int i = 0; i < n; i++) {
        // Check if removing the current element keeps the average unchanged
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++; // Increment the count
            sb << (i + 1) << " "; // Append the index (plus one) to the stringstream
        }
    }

    // Print the count of valid elements and the indices of these elements
    cout << c << endl;
    cout << sb.str() << endl; // Print the stringstream as a string

    return 0; // Return 0 to indicate successful execution
}

