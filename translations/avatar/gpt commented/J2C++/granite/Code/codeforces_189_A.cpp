
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    // Read the total number of items (n) to be processed
    // Define the maximum size for the dp array
    // Read three integer values (a, b, c) which represent the sizes of items
    // Store the sizes of items in an array for easier access
    // Initialize a dp array to store the maximum number of items that can be formed
    // Set all dp values to Integer.MIN_VALUE to indicate uncomputed states
    // Base case: zero items can be formed with zero size
    // Iterate through each item size (a, b, c)
    // Update the dp array for each possible size from the current item size
    // Calculate the maximum number of items that can be formed
    // Output the maximum number of items that can be formed with size n
    // End with comment "