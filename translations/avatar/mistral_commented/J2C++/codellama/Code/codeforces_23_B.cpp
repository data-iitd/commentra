
#include <iostream>

using namespace std;

// Create a new Scanner object to read input from the console
int main() {
    Scanner scan; // Initialize the Scanner object

    // Read the number of test cases from the input
    int t;
    cin >> t;

    // Iterate through each test case
    for (int i = 0; i < t; i++) {
        int n; // Read the number of elements in the array
        cin >> n;

        // Print the maximum left sum
        cout << maxLeft(n) << endl;
    }

    // Close the Scanner object to free up system resources
    scan.close();

    return 0;
}

// Function to calculate the maximum sum of elements to the left of a given index
int maxLeft(int n) {
    // Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
    return n > 2 ? n - 2 : 0;
}

