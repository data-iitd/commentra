#include <iostream> // Step 1: Include the necessary header for input/output.
#include <vector>   // Step 2: Include the vector header for dynamic array.
#include <cmath>    // Step 3: Include the cmath header for the abs function.

using namespace std; // Step 4: Use the standard namespace.

int main() { // Step 5: Implement the main function.
    int n; // Step 6: Declare a variable to store the size of the array.
    cin >> n; // Step 7: Read the size of the array from the user.
    
    vector<long> arr(n); // Step 8: Create a vector to store the elements of the array.
    for (int i = 0; i < n; i++) { // Step 9: Read the elements of the array from the user.
        cin >> arr[i]; 
    }
    
    long answer = abs(arr[0]); // Step 10: Initialize a variable to store the answer.
    for (int i = 1; i < n; i++) { // Step 11: Calculate the absolute difference between consecutive elements and add it to the answer.
        answer += abs(arr[i] - arr[i - 1]); 
    }
    
    cout << answer << endl; // Step 12: Print the final answer.
    return 0; // Step 13: Return 0 to indicate successful execution.
}

// <END-OF-CODE>
