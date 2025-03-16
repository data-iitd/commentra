#include <iostream> // Including the iostream library for input and output

using namespace std; // Using the standard namespace

int main() {
    // Declaring two integer variables 'a' and 'b'
    int a, b;
    
    // Reading two integer values from the user
    cin >> a >> b;
    
    // Checking if the first integer 'a' is positive
    if (a > 0) {
        cout << "Positive" << endl; // Output "Positive" if 'a' is greater than 0
    } 
    // Checking if the second integer 'b' is non-negative (zero or positive)
    else if (b >= 0) {
        cout << "Zero" << endl; // Output "Zero" if 'b' is greater than or equal to 0
    } 
    // Checking if the difference between 'b' and 'a' plus 1 is even
    else if ((b - a + 1) % 2 == 0) {
        cout << "Positive" << endl; // Output "Positive" if the result is even
    } 
    // If none of the above conditions are met, it means the result is negative
    else {
        cout << "Negative" << endl; // Output "Negative" for all other cases
    }
    
    return 0; // Returning 0 to indicate that the program executed successfully
}

