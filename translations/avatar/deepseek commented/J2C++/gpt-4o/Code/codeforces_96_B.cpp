#include <iostream>
#include <string>

int main() {
    // Create a new variable to read input from the user
    long long number;
    std::cin >> number;
    
    // Initialize two variables, ans and value, to -1 and 0, respectively
    long long ans = -1, value = 0;
    
    // Set a mask variable to 2
    int mask = 2;
    
    // The code enters a while loop that continues as long as value is less than the input number
    while (value < number) {
        // Convert the mask value to a binary string
        std::string s = std::bitset<32>(mask++).to_string();
        
        // Remove leading zeros
        s = s.substr(s.find('1'));
        
        // Count the number of zeros in the binary string and store it in the zeros variable
        int zeros = 0;
        for (char c : s) {
            if (c == '0') {
                zeros++;
            }
        }
        
        // If the number of zeros is not equal to the number of ones, skip the rest of the loop and increment the mask
        if (zeros != s.length() - zeros) {
            continue;
        }
        
        // Replace all zeros with 4 and all ones with 7 in the binary string
        for (char &c : s) {
            if (c == '0') {
                c = '4';
            } else {
                c = '7';
            }
        }
        
        // Convert the modified string back to a long integer
        value = std::stoll(s);
    }
    
    // Print the value variable
    std::cout << value << std::endl;

    return 0;
}

// <END-OF-CODE>
