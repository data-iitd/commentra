#include <iostream>
#include <string>

using namespace std;

int main() {
    // Read a line of input from the user
    string s;
    getline(cin, s);
    
    // Get the length of the input string
    int length = s.length();
    
    // Initialize a character variable to store the last non-space, non-question mark character
    char ch = 0;
    
    // Loop through the string in reverse to find the last relevant character
    for (int i = length - 1; i >= 0; i--) {
        // Check if the current character is not a space or a question mark
        if (s[i]!='' && s[i]!= '?') {
            ch = s[i]; // Store the character
            break; // Exit the loop once the character is found
        }
    }
    
    // Convert the character to lowercase for uniform comparison
    ch = tolower(ch);
    
    // Check if the character is a vowel or 'y'
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        cout << "YES" << endl; // Print "YES" if it is a vowel
    } else {
        cout << "NO" << endl; // Print "NO" if it is not a vowel
    }
    
    return 0;
}
