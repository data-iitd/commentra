
#include <iostream>
#include <string>

using namespace std;

// Method to generate a character array from the concatenation of numbers 1 to 1000
char* generateString() {
    string str = ""; // Creating an empty string to efficiently build the string
    
    // Looping through numbers 1 to 1000 and appending them to the string
    for (int i = 1; i <= 1000; i++) {
        str += to_string(i); // Appending the current number to the string
    }
    
    // Converting the built string to a character array and returning it
    return str.c_str();
}

int main() {
    int n; // Declaring an integer variable to store the user input
    
    // Reading an integer input from the user
    cin >> n;
    
    // Printing the character at the (n-1)th index of the generated character array
    cout << generateString()[n - 1] << endl;
    
    return 0;
}

