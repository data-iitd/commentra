#include <iostream>
#include <string>

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    // Making 'a' greater than 'b'
    if (a < b) {
        std::swap(a, b);
    }
    
    // Finding the GCD using Euclidean algorithm
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    // Returning the GCD
    return a;
}

// Function to solve the problem
void solve() {
    // Reading the input string from standard input
    std::string s;
    std::cin >> s;
    
    // Initializing an empty string 't' to store the output string
    std::string t = "";
    
    // Iterating through each character in the input string 's'
    int i = 0;
    while (i < s.length()) {
        // If the current character is 'A', append 'A' to 't' and move to the next character
        if (s[i] == 'A') {
            t += 'A';
            ++i;
        }
        // If the current character is 'B', check if the next character is 'C'. If yes, append 'D' to 't' and move to the next character (two steps ahead). If no, append 'X' to 't' and move to the next character
        else if (s[i] == 'B') {
            if (i < s.length() - 1) {
                if (s[i + 1] == 'C') {
                    t += 'D';
                    i += 2;
                } else {
                    t += 'X';
                    ++i;
                }
            } else {
                t += 'X';
                ++i;
            }
        }
        // If the current character is not 'A' or 'B', append 'X' to 't' and move to the next character
        else {
            t += 'X';
            ++i;
        }
    }
    
    // Initializing variables 'total' and 'numA' to 0
    int total = 0;
    int numA = 0;
    
    // Iterating through each character in the output string 't'
    for (int i = 0; i < t.length(); ++i) {
        // If the current character is 'X', reset 'numA' to 0
        if (t[i] == 'X') {
            numA = 0;
        }
        // If the current character is 'A', increment 'numA' by 1
        else if (t[i] == 'A') {
            ++numA;
        }
        // Adding the product of the number of 'A's in the current segment and the previous segment to 'total'
        total += numA;
    }
    
    // Printing the final answer
    std::cout << total << std::endl;
}

// Starting the program if the script is run directly
int main() {
    // Calling the 'solve' function
    solve();
    
    return 0;
}
