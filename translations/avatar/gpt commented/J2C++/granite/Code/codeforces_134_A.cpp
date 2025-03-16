
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    // Read the number of elements in the array
    int n;
    cin >> n;

    // Initialize an array to hold the integers and a variable to store the sum
    vector<int> arr(n);
    int sum = 0;

    // Read the integers into the array and calculate the sum
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i]; // Accumulate the sum of the elements
    }

    // Initialize a counter for valid indices and a string to store the output
    int c = 0;
    string output;

    // Check each element to see if it can be the "removed" element
    for (int i = 0; i < n; i++) {
        // Check if removing arr[i] results in the average of the remaining elements being equal to arr[i]
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++; // Increment the count of valid indices
            output += to_string(i + 1) + " "; // Append the 1-based index to the output string
        }
    }

    // Output the count of valid indices
    cout << c << endl;

    // Output the indices of valid elements
    cout << output << endl;

    return 0;
}
