#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for using dynamic arrays
#include <algorithm> // Including the algorithm library for sorting
using namespace std; // Using the standard namespace

int main() { // Main function to start the program
    int n; // Variable to store the number of elements in the array
    cin >> n; // Reading the number of elements from the user

    // Allocating memory for the array using a vector
    vector<long long> ans(n); 
    for (int i = 0; i < n; i++) {
        cin >> ans[i]; // Reading each element of the array one by one
    }

    // Sorting the array in ascending order
    sort(ans.begin(), ans.end());

    // Initializing a variable to keep track of the count
    long long count = ans[n - 1]; // The last element of the sorted array is the maximum element

    // Iterating through the array from the second last element to the first
    for (int i = n - 2; i >= 0; i--) {
        // If the current element is less than the next element, add it to the count
        if (ans[i] < ans[i + 1]) {
            count += ans[i];
        } else { // If the current element is greater than or equal to the next element
            // Decrement the current element until it becomes less than the next element
            while (ans[i] >= ans[i + 1]) {
                ans[i]--;
            }

            // If the current element is still greater than or equal to the next element, add it to the count
            if (ans[i] > 0) {
                count += ans[i];
            }
        }
    }

    // Printing the final count
    cout << count << endl; 
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
