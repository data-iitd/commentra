#include <iostream>
#include <string>

using namespace std;

int main() {
    // Declare a string variable to hold the input
    string s;
    
    // Read input string from the user
    cin >> s;
    
    // Declare variables to store the positions of 'A' and 'Z'
    int a, z;
    
    // Loop through the string to find the first occurrence of 'A'
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            a = i; // Store the index of 'A'
            break; // Exit the loop once 'A' is found
        }
    }
    
    // Loop through the string in reverse to find the last occurrence of 'Z'
    for(int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'Z') {
            z = i; // Store the index of 'Z'
            break; // Exit the loop once 'Z' is found
        }
    }
    
    // Calculate the number of characters between 'A' and 'Z' (inclusive) and print the result
    cout << z - a + 1 << endl;
    
    // Return 0 to indicate successful completion of the program
    return 0;
}
