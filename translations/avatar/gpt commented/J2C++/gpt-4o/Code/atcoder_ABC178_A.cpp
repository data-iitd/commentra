#include <iostream> // Including the iostream library for input and output
using namespace std;

int main() {
    // Creating a variable to read input from the console
    int x;
    
    // Reading an integer input from the user
    cin >> x;
    
    // Using a ternary operator to determine the boolean value based on the input
    bool boolValue = (x == 1) ? true : false;
    
    // Setting the result based on the boolean value; if boolValue is false, result is 1, otherwise 0
    int result = !boolValue ? 1 : 0;
    
    // Printing the result to the console
    cout << result << endl;
    
    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
