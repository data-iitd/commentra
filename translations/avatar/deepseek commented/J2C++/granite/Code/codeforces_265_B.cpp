
#include <bits/stdc++.h> // Include the necessary header files
using namespace std; // Use the standard namespace

int main() {
    int n; // Declare and initialize the variable n
    cin >> n; // Read the size of the array from the user
    
    int arr[n]; // Declare an array of size n
    
    // Read n integers into the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int ans = arr[0] + 1; // Initialize ans with the value of the first element plus 1
    
    // Iterate through the array and update ans
    for (int i = 1; i < n; i++) {
        ans += abs(arr[i] - arr[i - 1]) + 2;
    }
    
    // Print the final value of ans
    cout << ans << endl; // Print the final value of ans
    
    return 0; // Return 0 to indicate successful execution of the program
}
