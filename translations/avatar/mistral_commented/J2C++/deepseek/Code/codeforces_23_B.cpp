#include <iostream>

using namespace std;

// Function to calculate the maximum sum of elements to the left of a given index
int maxLeft(int n) {
    // Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
    return n > 2 ? n - 2 : 0;
}

int main() {
    // Create a new Scanner object to read input from the console
    int t;
    cin >> t; // Read the number of test cases from the input

    // Iterate through each test case
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n; // Read the number of elements in the array

        // Print the maximum left sum
        cout << maxLeft(n) << endl;
    }

    return 0;
}

