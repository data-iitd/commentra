
#include <iostream> // Including the necessary header file
#include <string> // Including the necessary header file

using namespace std; // Using the standard namespace

int main() {
    // Creating a Scanner object to read input from the user
    string s; // Declaring a string variable to store the binary representation
    cin >> s; // Reading a string input from the user
    
    // Initializing a counter to count the number of '1's in the binary representation
    int ans = 0;
    
    // Iterating through the binary string to count '1's
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') { // Checking if the current character is '1'
            ans++; // Incrementing the count of '1's
        }
    }
    
    // Printing the total count of '1's in the binary representation
    cout << ans << endl; // Printing the count of '1's
    
    return 0; // Returning 0 to indicate successful execution of the program
}

