
#include <iostream> // Including the necessary header file for input/output operations

using namespace std; // Using the standard namespace for input/output operations

int main() {
    int t; // Declaring the variable to store the number of test cases
    cin >> t; // Reading the number of test cases from the console
    
    int count = 0; // Initializing a counter to keep track of valid cases
    
    // Looping through each test case
    while (t-- > 0) {
        int a, b, c; // Declaring variables to store the three integers
        cin >> a >> b >> c; // Reading the three integers from the console
        
        // Checking if at least one of the integers is equal to 1
        if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1)) {
            count++; // Incrementing the count if the condition is met
        }
    }
    
    // Outputting the total count of valid cases
    cout << count << endl; // Outputting the count to the console
    
    return 0; // Returning 0 to indicate successful execution of the program
}

