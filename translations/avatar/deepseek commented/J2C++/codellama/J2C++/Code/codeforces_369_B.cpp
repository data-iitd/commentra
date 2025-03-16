#include <iostream> // Importing necessary classes for input handling
#include <cmath> // Importing necessary classes for mathematical operations

using namespace std; // Using the standard namespace

int main() {
    int n, k, l, r, sAll, sk; // Declaring variables to store the input values
    
    cin >> n >> k >> l >> r >> sAll >> sk; // Reading the input values
    
    int ans[n]; // Declaring an array to store the result
    fill(ans, ans + n, l); // Filling the array with the lower bound value 'l'
    
    // Subtracting the initial points for the first group and the remaining elements
    sAll -= sk + (n - k) * l;
    sk -= k * l;
    
    // Distributing the remaining points to the first group until sk is zero
    while (sk > 0) {
        int idx = n - 1; // Starting from the last element in the array
        while (sk > 0 && idx >= n - k) {
            ans[idx--]++; // Incrementing the points and moving to the previous element
            sk--; // Decrementing the remaining points to distribute
        }
    }
    
    // Distributing the remaining points to the remaining elements until sAll is zero
    while (sAll > 0) {
        int idx = 0; // Starting from the first element in the array
        while (sAll > 0 && idx < n - k) {
            ans[idx++]++; // Incrementing the points and moving to the next element
            sAll--; // Decrementing the remaining points to distribute
        }
    }
    
    for (int i = 0; i < n; i++) { // Iterating through the result array to print each element
        cout << ans[i] << " "; // Printing each element followed by a space
    }
    
    return 0; // Returning the result
}

