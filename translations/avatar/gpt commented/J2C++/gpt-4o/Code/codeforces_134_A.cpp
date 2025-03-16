#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    // Create a variable to read input from the user
    int n;
    
    // Read the number of elements in the array
    cin >> n;
    
    // Initialize a vector to hold the integers and a variable to store the sum
    vector<int> arr(n);
    int sum = 0;
    
    // Read the integers into the vector and calculate the sum
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i]; // Accumulate the sum of the elements
    }
    
    // Initialize a counter for valid indices and a stringstream for output
    int c = 0;
    stringstream ss;
    
    // Check each element to see if it can be the "removed" element
    for (int i = 0; i < n; i++) {
        // Check if removing arr[i] results in the average of the remaining elements being equal to arr[i]
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++; // Increment the count of valid indices
            ss << (i + 1) << " "; // Append the 1-based index to the stringstream
        }
    }
    
    // Output the count of valid indices
    cout << c << endl;
    
    // Output the indices of valid elements
    cout << ss.str() << endl;

    return 0;
}

// <END-OF-CODE>
