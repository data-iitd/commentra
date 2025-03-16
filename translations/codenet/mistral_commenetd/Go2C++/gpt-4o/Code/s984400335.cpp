// Including necessary header files
#include <iostream>
#include <algorithm> // For std::min

// Using the standard namespace
using namespace std;

// Function declaration for finding the minimum number among given integers
int min(int nums[], int size) {
    // Initializing the minimum value with the first integer
    int minValue = nums[0];

    // Iterating through the array 'nums' to find the minimum value
    for (int i = 1; i < size; i++) {
        // If the current value is less than the minimum value, update the minimum value
        if (nums[i] < minValue) {
            minValue = nums[i];
        }
    }

    // Returning the minimum value
    return minValue;
}

// Main function declaration
int main() {
    // Declaring three integer variables for reading input values
    int n, a, b;

    // Reading input values from the standard input using 'cin'
    cin >> n >> a >> b;

    // Declaring an array to hold the values for comparison
    int values[2] = {n * a, b};

    // Printing the minimum value between 'n*a' and 'b' using 'cout'
    cout << min(values, 2) << endl;

    return 0;
}

// <END-OF-CODE>
