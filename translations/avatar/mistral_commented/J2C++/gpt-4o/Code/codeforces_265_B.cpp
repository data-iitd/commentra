// Include necessary headers for input/output and collections
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define the main function, which is the entry point of the program
int main() {
    // Create a variable to read the size of the array
    int n;
    cin >> n;

    // Create a vector to store the integers
    vector<int> arr(n);

    // Use a for loop to read n integers from the standard input and store them in the vector arr
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Read the next integer and store it in the current index of the vector
    }

    // Initialize a variable ans with the first element of the array and add 1 to it
    int ans = arr[0] + 1;

    // Use another for loop to iterate through the remaining elements of the array arr
    for (int i = 1; i < n; i++) {
        // Calculate the absolute difference between the current and previous elements and add it to the variable ans along with 2
        ans += abs(arr[i] - arr[i - 1]) + 2;
    }

    // Finally, print the value of ans to the standard output
    cout << ans << endl;

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
