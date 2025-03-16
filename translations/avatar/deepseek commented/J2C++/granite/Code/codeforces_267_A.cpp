
#include <iostream>
#include <cmath>

using namespace std;

// Define the sub method to calculate the greatest common divisor using the Euclidean algorithm
int sub(int a, int b) {
    // Initialize min and max to store the smaller and larger of the two input values
    int min = min(a, b);
    int max = max(a, b);
    
    // Initialize result to 0, which will be used to store the result of the Euclidean algorithm
    int result = 0;
    
    // Apply the Euclidean algorithm until min becomes 0
    while (min > 0) {
        // Add the quotient of max divided by min to result
        result += max / min;
        
        // Update max to be the remainder of max divided by min
        max = max % min;
        
        // Swap min and max if necessary to ensure min is the smaller value
        int curr_min = min(min, max);
        int curr_max = max(min, max);
        min = curr_min;
        max = curr_max;
    }
    
    // Return the value of result, which represents the greatest common divisor
    return result;
}

int main() {
    // Create a new Scanner object to read input from the user
    Scanner scan;
    
    // Read an integer value n from the user and store it in the variable n
    int n;
    cin >> n;
    
    // Loop n times to read pairs of integers and print their greatest common divisor
    for (int i = 0; i < n; i++) {
        // Read two integers a and b from the user and store them in the variables a and b
        int a, b;
        cin >> a >> b;
        
        // Call the sub method with the values of a and b as arguments and print the result
        cout << sub(a, b) << endl;
    }
    
    return 0;
}

