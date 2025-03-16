
#include <iostream> // Including the necessary header file for input/output operations
#include <string> // Including the necessary header file for string operations

using namespace std; // Using the standard namespace for convenience

// Function to generate a string from the concatenation of numbers 1 to 1000
string generateString() {
    string result; // Creating an empty string to store the generated string
    
    // Looping through numbers 1 to 1000 and appending them to the string
    for (int i = 1; i <= 1000; i++) {
        result += to_string(i); // Appending the current number to the string
    }
    
    return result; // Returning the generated string
}

int main() {
    int n; // Declaring an integer variable to store the user input
    
    // Reading an integer input from the user
    cin >> n;
    
    // Printing the character at the (n-1)th index of the generated string
    cout << generateString()[n - 1] << endl; // Using the [] operator to access the character at the specified index
    
    return 0; // Returning 0 to indicate successful program execution
}

