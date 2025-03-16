
#include <iostream>
#include <string>

using namespace std;

void printIsland(int n, int count) {
    // Calculate the number of 'L' and 'S' characters that can be placed on the island
    int a = (n + 1) / 2; // Number of 'L' characters in the first half
    int b = n / 2;       // Number of 'L' characters in the second half
    int max = a * a + b * b; // Maximum number of 'L' characters that can fit in the island
    
    // Check if the provided count exceeds the maximum possible 'L' characters
    if (count > max) {
        cout << "NO" << endl; // Print "NO" if the count is too high
        return; // Exit the function
    }
    
    // If the count is valid, print "YES"
    cout << "YES" << endl;
    
    // Loop through each row of the island
    for (int i = 0; i < n; i++) {
        string row = ""; // Create an empty string to construct the row
        
        // Loop through each column of the island
        for (int j = 0; j < n; j++) {
            // Place 'L' if the sum of indices is even and there are still 'L' characters left
            if ((i + j) % 2 == 0 && count > 0) {
                row += 'L'; // Append 'L' to the current row
                count--; // Decrement the count of 'L' characters
            } else {
                row += 'S'; // Append 'S' to the current row
            }
        }
        
        // Print the constructed row of the island
        cout << row << endl;
    }
}

int main() {
    // Create a Scanner object to read input from the console
    int n, count;
    cin >> n >> count;
    
    // Call the function to print the island pattern based on the input values
    printIsland(n, count);
    
    return 0;
}

