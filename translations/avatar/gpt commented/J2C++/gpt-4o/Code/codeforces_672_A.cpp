#include <iostream> // Including the iostream library for input and output
#include <string>   // Including the string library for string manipulation

using namespace std;

// Function to generate a character array from the concatenation of numbers 1 to 1000
string generateString() {
    string result; // Creating a string to hold the concatenated numbers
    
    // Looping through numbers 1 to 1000 and appending them to the result string
    for (int i = 1; i <= 1000; i++) {
        result += to_string(i); // Appending the current number to the result string
    }
    
    // Returning the built string
    return result;
}

int main() {
    int n; // Variable to hold user input
    cin >> n; // Reading an integer input from the user
    
    // Printing the character at the (n-1)th index of the generated string
    cout << generateString()[n - 1] << endl;
    
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
