
#include <iostream> // Importing the iostream library for input/output operations

using namespace std;

int main() {
    int n, i, j, p = 97; // 'p' is initialized to 97, which is the ASCII value for 'a'
    
    cout << "Enter the size of the character array: "; // Prompt the user to enter the size of the array
    cin >> n; // Read the integer input from the user
    
    char c[n]; // Declare a character array of size 'n'
    
    for (i = 0; i < 4; i++) { // Loop through the first 4 positions
        for (j = i; j < n; j += 4) { // Fill every 4th position starting from 'i'
            c[j] = (char) p; // Assign the character corresponding to ASCII value 'p'
            p++; // Increment 'p' to get the next character
        }
    }
    
    for (i = 0; i < n; i++) {
        cout << c[i]; // Output each character in the array
    }
    
    return 0;
}

