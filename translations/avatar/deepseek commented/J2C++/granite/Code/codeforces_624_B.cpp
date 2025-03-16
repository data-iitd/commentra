
#include <iostream> // Include standard input/output stream objects
#include <algorithm> // Include utility header for sorting algorithms

using namespace std; // Use the standard namespace

int main() {
    int n; // Declare integer variable n to store the number of elements
    cin >> n; // Read the number of elements from the user
    
    long long ans[n]; // Declare array ans to store long integers
    
    // Populate the array with input values
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }
    
    // Sort the array in ascending order
    sort(ans, ans + n); // Use the built-in sort function from the algorithm library
    
    // Initialize count with the largest element in the array
    long long count = ans[n - 1];
    
    // Iterate through the array from the second-to-last element to the first
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
    cout << count << endl; // Use the standard output stream object to display the result
    
    return 0; // Return 0 to indicate successful program execution
}
