
#include <iostream> // Include the necessary libraries
#include <string>

using namespace std;

int main() {
    string s; // Declare a string variable to store the input
    getline(cin, s); // Read a line of input from the user
    
    int length = s.length(); // Get the length of the input string
    
    char ch = 0; // Initialize a character variable to store the last non-space, non-question mark character
    
    for (int i = length - 1; i >= 0; i--) { // Loop through the string in reverse to find the last relevant character
        if (s[i]!='' && s[i]!= '?') {
            ch = s[i]; // Store the character
            break; // Exit the loop once the character is found
        }
    }
    
    ch = tolower(ch); // Convert the character to lowercase for uniform comparison
    
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        cout << "YES" << endl; // Print "YES" if it is a vowel
    } else {
        cout << "NO" << endl; // Print "NO" if it is not a vowel
    }
    
    return 0; // Return 0 to indicate successful execution
}

