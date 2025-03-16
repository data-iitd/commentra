
#include <iostream> // Including necessary libraries for input handling and array operations
#include <vector> // Including necessary library for vector operations

using namespace std; // Using the standard namespace for input handling and array operations

vector<int> getPoints(int n, int k, int l, int r, int sAll, int sk) {
    vector<int> ans(n, l); // Initializing a vector to store the result
    sAll -= sk + (n - k) * l; // Subtracting the initial points for the first group and the remaining elements
    sk -= k * l; // Subtracting the initial points for the first group
    
    // Distributing the remaining points to the first group until sk is zero
    while (sk > 0) {
        int idx = n - 1; // Starting from the last element in the vector
        while (sk > 0 && idx >= n - k) {
            ans[idx--]++; // Incrementing the points and moving to the previous element
            sk--; // Decrementing the remaining points to distribute
        }
    }
    
    // Distributing the remaining points to the remaining elements until sAll is zero
    while (sAll > 0) {
        int idx = 0; // Starting from the first element in the vector
        while (sAll > 0 && idx < n - k) {
            ans[idx++]++; // Incrementing the points and moving to the next element
            sAll--; // Decrementing the remaining points to distribute
        }
    }
    
    return ans; // Returning the result vector
}

int main() {
    int n, k, l, r, sAll, sk; // Declaring variables to store the input values
    cin >> n >> k >> l >> r >> sAll >> sk; // Reading the input values from the user
    
    vector<int> ans = getPoints(n, k, l, r, sAll, sk); // Calling the getPoints function to compute the result
    
    for (int num : ans) { // Iterating through the result vector to print each element
        cout << num << " "; // Printing each element followed by a space
    }
    
    return 0; // Returning 0 to indicate successful execution of the program
}

