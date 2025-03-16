#include <iostream>
#include <string>

using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    long number;
    cin >> number;
    
    // Initialize variables to store the result and the current value
    long ans = -1, value = 0;
    
    // Initialize a mask variable starting from 2
    int mask = 2;
    
    // Loop until the current value is less than the input number
    while (value < number) {
        // Convert the current mask to a binary string and remove the leading '1'
        string s = bitset<32>(mask++).to_string().substr(1);
        
        // Initialize a counter for zeros in the binary string
        int zeros = 0;
        
        // Count the number of '0's in the binary string
        for (char c : s) {
            if (c == '0') zeros++;
        }
        
        // If the number of zeros is not equal to the number of ones, skip to the next iteration
        if (zeros != s.length() - zeros) continue;
        
        // Replace '0's with '4's and '1's with '7's to form a new number
        s = s.replace(0, '4');
        s = s.replace(1, '7');
        
        // Parse the modified string as a long integer
        value = stol(s);
    }
    
    // Print the final value that meets the condition
    cout << value << endl;
    
    return 0;
}

