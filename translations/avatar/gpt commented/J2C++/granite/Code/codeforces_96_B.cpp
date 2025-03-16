
#include <iostream> // Include the necessary header file for input/output operations
#include <string> // Include the necessary header file for string manipulation

using namespace std; // Use the standard namespace for input/output operations

int main() {
    // Create a variable to store the input number
    long number;
    
    // Read a long integer from user input
    cin >> number;
    
    // Initialize variables to store the result and the current value
    long ans = -1, value = 0;
    
    // Initialize a mask variable starting from 2
    int mask = 2;
    
    // Loop until the current value is less than the input number
    while (value < number) {
        // Convert the current mask to a binary string and remove the leading '1'
        string s = bitset<64>(mask++).to_string().substr(1);
        
        // Initialize a counter for zeros in the binary string
        int zeros = 0;
        
        // Count the number of '0's in the binary string
        for (char c : s) {
            if (c == '0') zeros++;
        }
        
        // If the number of zeros is not equal to the number of ones, skip to the next iteration
        if (zeros!= s.length() - zeros) continue;
        
        // Replace '0's with '4's and '1's with '7's to form a new number
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') s[i] = '4';
            else if (s[i] == '1') s[i] = '7';
        }
        
        // Parse the modified string as a long integer
        value = stol(s);
    }
    
    // Print the final value that meets the condition
    cout << value << endl;
    
    // End the program
    return 0;
}
